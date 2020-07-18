/**
 * @file tcpserverlic.cpp
 * @brief	
 * @author My name SunWu
 * @version 
 * @date 2019-08-25
 */

#include <iostream>
#include <mutex>
#include <unistd.h>
#include <stdio.h>
#include <poll.h>
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
#include <liburing.h>

int epfd = 0;

enum PollType
{
	POLL_IDLE 	= 0, //空闲
	POLL_READ	= 1, //读取
	POLL_WRITE	= 2, //写入
	POLL_ERROR	= 3, //错误
};

struct PollData
{
	PollType type = POLL_IDLE;
	int conn_fd = 0;
};

#define MAX_CONNECTIONS 128

static struct PollData connections[MAX_CONNECTIONS];

void initConnections()
{
	for (auto& it : connections) {
		it.conn_fd = -1;
	}
}

std::mutex cmutex;

struct PollData* getConnectionRecord()
{
	std::lock_guard<std::mutex> guard(cmutex);
	for (auto& it : connections) {
		if (it.conn_fd == -1)
			return &it;
	}

	return nullptr;
}

void newTCPTask(int sock)
{
	std::cout<<"one client come in:"<<sock<<std::endl;
	struct io_uring ring;
	io_uring_queue_init(32, &ring, 0);


	int num = 1;
	while(true) {

		std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(1000));

		for (;;) {
			struct io_uring_sqe *sqe = io_uring_get_sqe(&ring);
			if (!sqe)
				break;
			std::string str = "hello world :";
			str += std::to_string(num++);
			const char* str1 = str.c_str();
			struct iovec iov = {
				.iov_base = (void*)str1,
				.iov_len = str.length(),
			};
			io_uring_prep_writev(sqe, sock, &iov, 1, 0);
		}

		io_uring_submit(&ring);

		struct io_uring_cqe *cqe;
		for (;;) {
			io_uring_peek_cqe(&ring, &cqe);
			if (!cqe) {
				//puts("Waiting write...");
				// accept 新连接，做其他事
			} else {
				//std::cout<<"Finished write."<<(char*)iov.iov_base<<std::endl;
				std::cout<<"Finished write."<<std::endl;
				break;
			}
		}

	}
}

void newTCPTask2(int sock)
{
	std::cout<<"one client come in:"<<sock<<std::endl;
	struct io_uring ring;
	io_uring_queue_init(32, &ring, 0);

	char buf[128] = {};
	struct iovec iov = {
		.iov_base = (void*)buf,
		.iov_len = 128,
	};

	while(true) {

		bzero( buf, sizeof(buf));
		struct io_uring_sqe *sqe = io_uring_get_sqe(&ring);
		io_uring_prep_readv(sqe, sock, &iov, 1, 0);
		io_uring_submit(&ring);

		std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(1000));

		struct io_uring_cqe *cqe;
		for (;;) {
			io_uring_peek_cqe(&ring, &cqe);
			if (!cqe) {
				//puts("Waiting read...");
				// accept 新连接，做其他事
			} else {
				std::cout<<"Finished read."<<(char*)iov.iov_base<<std::endl;
				break;
			}
		}
	}
}

int main()
{
	initConnections();

	int sock = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == -1) {
		std::cout<<"create socket error"<<std::endl;
		return 0;
	}

	struct sockaddr_in addr;
	bzero( &addr, sizeof( addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9001);
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

	struct io_uring ring;
	io_uring_queue_init(32, &ring, 0);

	socklen_t len = sizeof(struct sockaddr_in);
	while(true) {
		struct io_uring_sqe* sqe = io_uring_get_sqe(&ring);
		io_uring_prep_poll_add(sqe, sock, POLLIN);
		io_uring_submit(&ring);

		struct io_uring_cqe *cqe;
		io_uring_wait_cqe(&ring, &cqe);

		struct sockaddr_in addrc;
		bzero( &addrc, sizeof( addrc));
		ret = ::accept(sock, (struct sockaddr*)&addrc, &len);

		if (ret != -1) {
			auto th1 = std::thread(newTCPTask, ret);
			th1.detach();
			auto th2 = std::thread(newTCPTask2, ret);
			th2.detach();
		
			//newTCPTask(ret);
		}
	}

	return 0;
}



