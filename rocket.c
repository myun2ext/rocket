#include "rocket.h"

ROCKET rocket(int socket_family, int socket_type, int protocol)
{
#ifdef WIN32
	rocket_wsa_startup();
#endif
	return socket(socket_family, socket_type, protocol);
}

struct addrinfo* rocket_address(const char* host, unsigned short port)
{
	struct addrinfo hints, *addr;
	char port_s[6];
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

#pragma warning(disable: 4996)
	sprintf(port_s, "%d", port);
#pragma warning(default: 4996)

	getaddrinfo(host, port_s, &hints, &addr);
	return addr;
}

int fire_tcp_rocket(ROCKET rock, const char* host, unsigned short port)
{
	struct addrinfo* addr = rocket_address(host, port);
	int ret= connect(rock, addr->ai_addr, addr->ai_addrlen);
	freeaddrinfo(addr);
	return ret;
}

 
int fire_udp_rocket(ROCKET rock, const char* host, unsigned short port)
{
	struct addrinfo* addr = rocket_address(host, port);
	int ret= bind(rock, addr->ai_addr, addr->ai_addrlen);
	freeaddrinfo(addr);
	return ret;
}

void destroy_rocket(ROCKET rock)
{
#ifdef WIN32
	closesocket(rock);
#else
	close(rock);
#endif
}

ROCKET listen_rocket(ROCKET rock, unsigned short port, int max_queing)
{
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(rock, (struct sockaddr*)&addr, sizeof(addr));
	listen(rock, max_queing);

	return rock;
}