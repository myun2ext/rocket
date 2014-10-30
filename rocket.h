#ifndef __MYUN2_GITHUB_ROCKET__ROCKET_H__
#define __MYUN2_GITHUB_ROCKET__ROCKET_H__

#ifdef WIN32
	#include <ws2tcpip.h>
	#include <Wspiapi.h>
	#include <winsock2.h>
#else
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <netdb.h>
#endif

#define ROCKET SOCKET

ROCKET rocket(int socket_family, int socket_type, int protocol);
struct sockaddr_in rocket_address(const char* host, unsigned short port);
void fire_rocket(ROCKET rock, const char* host, unsigned short port);
void fire_udp_rocket(ROCKET rock, const char* host, unsigned short port);
void destroy_rocket(ROCKET rock);
ROCKET listen_rocket(ROCKET rock, unsigned short port, int max_queing);

#endif//__MYUN2_GITHUB_ROCKET__ROCKET_H__