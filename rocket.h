#ifndef __MYUN2_GITHUB_ROCKET__ROCKET_H__
#define __MYUN2_GITHUB_ROCKET__ROCKET_H__

#ifdef WIN32
	#include <ws2tcpip.h>
	#include <Wspiapi.h>
	#include <winsock2.h>
	#define ROCKET SOCKETS

	#define is_valid_rocket(r)		(r != INVALID_SOCKET)
	#define is_invalid_rocket(r)	(r == INVALID_SOCKET)
#else
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <netdb.h>
	#define ROCKET int

	#define is_valid_rocket(r)		(r != -1)
	#define is_invalid_rocket(r)	(r == -1)
#endif


ROCKET rocket(int socket_family, int socket_type, int protocol);
struct addrinfo* rocket_address(const char* host, unsigned short port);
int fire_tcp_rocket(ROCKET rock, const char* host, unsigned short port);
int fire_udp_rocket(ROCKET rock, const char* host, unsigned short port);
void destroy_rocket(ROCKET rock);
ROCKET listen_rocket(ROCKET rock, unsigned short port, int max_queing);

#define tcp_rocket()	rocket(AF_INET, SOCK_STREAM, 0)
#define udp_rocket()	rocket(AF_INET, SOCK_DGRAM, 0)

/* reciever */
typedef struct
{
	int socket_family, socket_type, protocol;
	int port, max_queing;
	void (*callback)(ROCKET rock, const struct sockaddr *from_addr, int from_addr_len);
} ROCKET_RECIEVER_SETTINGS;

void rocket_reciever(const ROCKET_RECIEVER_SETTINGS* settings);
void tcp_rocket_reciever(ROCKET_RECIEVER_SETTINGS* settings);

#endif//__MYUN2_GITHUB_ROCKET__ROCKET_H__
