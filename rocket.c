#include "rocket.h"

ROCKET rocket(int socket_family, int socket_type, int protocol)
{
#ifdef WIN32
	rocket_wsa_startup();
#endif
	return socket(socket_family, socket_type, protocol);
}

struct sockaddr_in rocket_address(const char* host, unsigned short port)
{
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(host);
	addr;
}

void fire_tcp_rocket(ROCKET rock, const char* host, unsigned short port)
{
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(host);
	connect(rock, (struct sockaddr *) &addr, sizeof(addr));
}

void fire_udp_rocket(ROCKET rock, const char* host, unsigned short port)
{
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(host);
	bind(rock, (struct sockaddr *) &addr, sizeof(addr));
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