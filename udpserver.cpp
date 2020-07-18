/**
 * @file	udpserver.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-04-02
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <iostream>

#define SOCKET_PORT		12345
#define LISTEN_BACKLOG	10
#define ARRAY_LENGTH	256


int main()
{
	int iSockServerFd;
	//int iSockClientFd;

	struct sockaddr_in tSocketServerAddr;
	struct sockaddr_in tSocketClientAddr;

	socklen_t iSockAddrLen;
	int iRet;

	unsigned char unRecvBuff[ARRAY_LENGTH + 1] = {};
	int iRecvLen;

	signal(SIGCHLD, SIG_IGN);

	iSockServerFd = socket(AF_INET, SOCK_DGRAM, 0);
	if (iSockServerFd  == -1) {
		std::cout<<"socket error"<<std::endl;
		return -1;
	}

	tSocketServerAddr.sin_family = AF_INET;
	tSocketServerAddr.sin_port = htons(SOCKET_PORT);
	tSocketServerAddr.sin_addr.s_addr= htonl(INADDR_ANY);
	//tSocketServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  
	memset(tSocketServerAddr.sin_zero, 0, 8);

	iSockAddrLen = sizeof(struct sockaddr);

	iRet = bind(iSockServerFd, (struct sockaddr*)&tSocketServerAddr, iSockAddrLen);
	if (iRet == -1){
		std::cout<<"socket bind error"<<std::endl;
		return -1;
	}

	while(1) {
		iRecvLen = recvfrom(iSockServerFd, unRecvBuff, ARRAY_LENGTH, 0, (struct sockaddr*)&tSocketClientAddr, &iSockAddrLen);
		if (iRecvLen < 0) {
			std::cout<<"recvfrom error"<<std::endl;
		} else {
			std::cout<<unRecvBuff<<std::endl;
		}
	}

	close(iSockServerFd);


	return 0;
}
