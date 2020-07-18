/**
 * @file tcpclient.cpp
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

int main()
{
	int sock = ::socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		std::cout<<"create socket error"<<std::endl;
		return 0;
	}

	struct sockaddr_in addr;
	bzero( &addr, sizeof( addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8100);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	int ret = ::connect(sock, (struct sockaddr*)&addr, sizeof(addr));
	if (ret == -1) {
		std::cout<<"bind socket error"<<std::endl;
		::close(sock);
		return 0;
	}

	epfd = epoll_create(100);

	struct epoll_event epfds;
	epfds.events = EPOLLIN | EPOLLOUT | EPOLLERR | EPOLLPRI;
	epfds.data.fd = sock;
	if (-1 == epoll_ctl(epfd, EPOLL_CTL_ADD, sock, &epfds)) {
		::close(sock);
		return 0;
	}

	int i = 0;
	while(true) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		struct epoll_event ev;
		int ret = epoll_wait(epfd, &ev, 1, 0);
		if (ret == 0) {
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			continue;
		}

		if (ev.events & (EPOLLERR | EPOLLPRI)) {
			std::cout<<"epoll wait error:"<<ev.events<<std::endl;
			::close(sock);
			return 0;
		}


		if ((i++ % 2 == 0) && (ev.events & (EPOLLIN))) {
			size_t len = 1024 * 64;
			char buf[len] = {};
			::recv(sock, buf, len, 0);
			std::cout<<"read buf:"<<buf<<std::endl;
			std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(1000));
		} 
		if ((i++ % 2 == 1) && (ev.events & (EPOLLOUT))) {
			std::stringstream oss;
			oss <<"client hello world this is :"<<i<<std::endl;
			::send(sock, oss.str().c_str(), oss.str().length(), MSG_NOSIGNAL);
		}
		std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(1000));

	}


	return 0;
}



