//// February 2006 using excellent code::blocks IDE with mingw
//// C++ Code for changing colors of text in the console window
//#include <iostream>
//#include <windows.h>
//
//using namespace std;
//
//int main()
//{
//
//	HANDLE hConsole;
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	// Use the three primary colors for mixing any other color.
//	// Use FOREGROUND_INTENSITY for brighter colors.
//	SetConsoleTextAttribute
//	(hConsole, FOREGROUND_GREEN );
//	cout << "Bright red text\n";
//
//	SetConsoleTextAttribute
//	(hConsole, FOREGROUND_BLUE );
//	cout << "Bright blue text\n";
//
//	SetConsoleTextAttribute
//	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//	cout << "Back to normal white text\n";
//
//	// Wait for user pressing key before exiting
//	// Gives them a chance to see the output
//	cout << "\n\nPress any key to exit program.....";
//	cin.get();
//
//	return 0;
//}
// color your text in Windows console mode
// colors are 0=black 1=blue 2=green and so on to 15=white  
// colorattribute = foreground + background * 16
// to get red text on yellow use 4 + 14*16 = 228
// light red on yellow would be 12 + 14*16 = 236
// a Dev-C++ tested console application by  vegaseat  07nov2004

//#include <iostream>
//#include <windows.h>   // WinApi header
//
//using namespace std;    // std::cout, std::cin
//
//int main()
//{
//	HANDLE  hConsole;
//	int k;
//
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	cout << 0 << " I want to be nice today!" << endl;
//
//	// you can loop k higher to see more color choices
//	for (k = 1; k < 16; k++)
//	{
//		// pick the colorattribute k you want
//		SetConsoleTextAttribute(hConsole, k);
//		cout << k << " I want to be nice today!" << endl;
//	}
//
//	system("pause");
//	return 0;
//}



// Microsoft Development Environment 2003 - Version 7.1.3088
// Copyright (r) 1987-2002 Microsoft Corporation. All Right Reserved
// Microsoft .NET Framework 1.1 - Version 1.1.4322
// Copyright (r) 1998-2002 Microsoft Corporation. All Right Reserved
//
// Run on Windows XP Pro machine, version 2002, SP 2
//
// <windows.h> already included...
// WINVER = 0x0501 for Xp already defined in windows.h

/*
	Simple udp client
*/
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#include <thread>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define SERVER "95.81.75.8"  //ip address of udp server
#define BUFLEN 512  //Max length of buffer
#define PORT 58326   //The port on which to listen for incoming data


int main(void)
{
	//std::thread t = std::thread(receive);

	struct sockaddr_in si_other;
	int s, slen = sizeof(si_other);
	char buf[BUFLEN];
	char message[BUFLEN];
	WSADATA wsa;

	//Initialise winsock
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		system("pause");
		return 0;
	}
	printf("Initialised.\n");

	//create socket
	if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR)
	{
		printf("socket() failed with error code : %d", WSAGetLastError());
		system("pause");
		return 0;
	}

	//setup address structure
	memset((char *)&si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);
	si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);




	//start communication
	while (1)
	{
	printf("Enter message : ");
	std::cin >> message;

	//send the message
	if (sendto(s, message, strlen(message), 0, (struct sockaddr *) &si_other, slen) == SOCKET_ERROR)
	{
		printf("sendto() failed with error code : %d", WSAGetLastError());
		system("pause");
		return 0;
	}

	//receive a reply and print it
	//clear the buffer by filling null, it might have previously received data
	memset(buf, '\0', BUFLEN);
	//try to receive some data, this is a blocking call
	if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == SOCKET_ERROR)
	{
		printf("recvfrom() failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}

	puts(buf);
	}

	int i = 0;


	closesocket(s);
	WSACleanup();
	system("pause");
	return 0;
}