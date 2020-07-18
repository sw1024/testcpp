/**
 * @file tcpserverlic.cpp
 * @brief	
 * @author My name SunWu
 * @version 
 * @date 2019-08-25
 */

#include <iostream>
#include <unistd.h>
#include <thread>
#include <vector>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sstream>
#include <string.h>

int epfd = 0;

void newTCPTask(int sock)
{
	std::cout<<"one client come in:"<<sock<<std::endl;
	int epfd2 = epoll_create(100);
	struct epoll_event epfds;
	epfds.events = EPOLLIN | EPOLLOUT | EPOLLERR | EPOLLPRI;
	epfds.data.fd = sock;
	if (-1 == epoll_ctl(epfd2, EPOLL_CTL_ADD, sock, &epfds)) {
		::close(sock);
		std::cout<<"sock close ctl err:"<<sock<<std::endl;
		return;
	}
	while(true) {
		std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(1000));
		struct epoll_event ev;
		int ret = epoll_wait(epfd2, &ev, 1, 0);
		if (ret <= 0) {
			std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(1));
			continue;
		}

		if (ev.events & (EPOLLERR | EPOLLPRI)) {
			::close(sock);
			std::cout<<"sock close:"<<ev.events<<std::endl;
			return;
		}

		if (ev.events & (EPOLLIN)) {
			size_t len = 1024 * 64;
			char buf[len] = {};
			::recv(sock, buf, len, 0);
			std::cout<<buf<<std::endl;
			std::cout<<"read buf:"<<buf<<std::endl;
			std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(1000));
		} 
		if (ev.events & (EPOLLOUT)) {
			std::stringstream oss;
			oss <<"hello world this is :"<<sock;
			::send(sock, oss.str().c_str(), oss.str().length(), MSG_NOSIGNAL);
			//std::cout<<oss.str().length()<<oss.str().c_str()<<std::endl;;
			std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(1000));
		}

	}
}

int main()
{
	int sock = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == -1) {
		std::cout<<"create socket error"<<std::endl;
		return 0;
	}

	struct sockaddr_in addr;
	bzero( &addr, sizeof( addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(20100);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	int ret = ::bind(sock, (struct sockaddr*)&addr, sizeof(addr));
	if (ret == -1) {
		std::cout<<"bind socket error"<<std::endl;
		::close(sock);
		return 0;
	}


	ret = ::listen(sock, 1000);
	if (ret == -1) {
		std::cout<<"listen socket error"<<std::endl;
		::close(sock);
	}

	epfd = epoll_create(100);
	struct epoll_event ev;
	ev.events = EPOLLIN;
	ev.data.fd = sock;
	ev.data.ptr = nullptr;
	if (-1 == epoll_ctl(epfd, EPOLL_CTL_ADD, sock, &ev)) {
		::close(sock);
		return 0;
	}

	socklen_t len = sizeof(struct sockaddr_in);
	while(true) {
		struct sockaddr_in addrc;
		bzero( &addrc, sizeof( addrc));

		struct epoll_event ev2;
		ret = epoll_wait(epfd, &ev2, 1, 0);
		if (ret == -1) {
			std::cout<<"epoll_wait error"<<std::endl;
			return 0;
		}
		if (ret == 1 && ev2.events & EPOLLIN)
			ret = ::accept(sock, (struct sockaddr*)&addrc, &len);
		else
			continue;
		if (ret != -1) {
			auto th1 = std::thread(newTCPTask, ret);
			th1.detach();
			auto th2 = std::thread(newTCPTask, ret);
			th2.detach();
		
			//newTCPTask(ret);
		}
	}

	return 0;
}



