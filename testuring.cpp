/**
 * @file testuring.cpp
 * @brief	
 * @author My name SunWu
 * @version 
 * @date 2019-10-21
 */

#include <liburing.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string>

int main()
{
	struct io_uring ring;
	io_uring_queue_init(32, &ring, 0);

	struct io_uring_sqe *sqe = io_uring_get_sqe(&ring);
	int fd = open("./test.txt", O_WRONLY | O_CREAT);
	std::string str = "hello world";
	const char* str1 = str.c_str();
	struct iovec iov = {
		.iov_base = (void*)str1,
		.iov_len = strlen("Hello world"),
	};
	io_uring_prep_writev(sqe, fd, &iov, 1, 0);
	io_uring_submit(&ring);

	struct io_uring_cqe *cqe;

	for (;;) {
		io_uring_peek_cqe(&ring, &cqe);
		if (!cqe) {
			puts("Waiting...");
			// accept 新连接，做其他事
		} else {
			puts("Finished.");
			break;
		}
	}
	io_uring_cqe_seen(&ring, cqe);
	io_uring_queue_exit(&ring);

	return 0;
}
