#include <iostream>
#include <winsock2.h>

using namespace std;

int main()
{
	WSADATA WSAData;
	SOCKET server;
	SOCKADDR_IN addr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_addr.s_addr = inet_addr("95.81.105.211"); // replace the ip with your futur server ip address. If server AND client are running on the same computer, you can use the local ip 127.0.0.1
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5555);

	connect(server, (SOCKADDR *)&addr, sizeof(addr));
	cout << "Connected to server!" << endl;

	char buffer[1024] = { 'h', 'e', 'l', 'l', 'o', '.' };
	send(server, buffer, sizeof(buffer), 0);
	cout << "Message sent!" << endl;

	closesocket(server);
	WSACleanup();
	cout << "Socket closed." << endl << endl;
}