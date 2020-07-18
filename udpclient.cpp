/**
 * @file	udpclient.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-04-02
 */


#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>



#define SOCKET_PORT		12345	// 设置服务器端的端口
#define ARRAY_LENGTH	256		// 设置缓冲区的大小


int main(int argc, char** argv)
{
	int iSocketClientFd;

	struct sockaddr_in tSocketServerAddr;
	int iSockAddrLen;
	int iSendLen;
	char ucSendBuf[ARRAY_LENGTH];
	int iRet;

	if (argc != 2) {
		std::cout<<"Usage:"<<argv[0]<<" <server_ip>\n";
		return -1;
	}

	iSocketClientFd = socket(AF_INET, SOCK_DGRAM, 0);
	if (iSocketClientFd == -1) {
		std::cout<<"socket error\n";
		return -1;
	}

	tSocketServerAddr.sin_family = AF_INET;
	tSocketServerAddr.sin_port = htonl(SOCKET_PORT);
	iRet = inet_aton(argv[1], &tSocketServerAddr.sin_addr);
	if (iRet == 0) {
		std::cout<<"server ip is not valid!"<<std::endl;
		return -1;
	}

	memset(tSocketServerAddr.sin_zero, 0, 8);
	iSockAddrLen = sizeof(struct sockaddr);

	std::cout<<"Input a message to "<<argv[1]<<std::endl;
	while(1) {
		if (fgets(ucSendBuf, ARRAY_LENGTH, stdin)) {
			iSendLen = sendto(iSocketClientFd, ucSendBuf, strlen(ucSendBuf), 0,
					(const struct sockaddr *)&tSocketServerAddr, iSockAddrLen);
			if(iSendLen <= 0) {
				printf("sendto error! %s\n", ucSendBuf);
				close(iSocketClientFd);
				return -1;
			}
		}
	}

	close(iSocketClientFd);
	return 0;
}
