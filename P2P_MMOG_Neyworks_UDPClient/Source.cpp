/*
	Simple udp client
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<stdio.h>
#include<winsock2.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define SERVER "95.81.75.8"  //ip address of udp server
#define BUFLEN 512  //Max length of buffer
#define PORT 6662   //The port on which to listen for incoming data

int main(void)
{
	// Create a connectionless socket
	SOCKET sUDPSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	// Check to see if we have a valid socket
	if (sUDPSocket == INVALID_SOCKET) {
		int iSocketError = WSAGetLastError();
		printf("error");
		system("pause");
		return FALSE;
	}

	// Set up the target device address. For this sample,
	// we are assuming it is a machine at 192.168.0.1, and on
	// port 40040
	SOCKADDR_IN sTargetDevice;
	memset(&sTargetDevice, 0, sizeof(SOCKADDR_IN));

	sTargetDevice.sin_family = AF_INET;
	sTargetDevice.sin_port = htons(PORT);
	sTargetDevice.sin_addr.s_addr = inet_addr(SERVER);

	// Send a datagram to the target device
	char cBuffer[1024] = "Test Buffer";
	int nBytesSent = 0;
	int nBufSize = strlen(cBuffer);

	nBytesSent = sendto(sUDPSocket, cBuffer, nBufSize, 0,
		(SOCKADDR *)&sTargetDevice,
		sizeof(SOCKADDR_IN));

	// Close the socket
	closesocket(sUDPSocket);
	system("pause");
}