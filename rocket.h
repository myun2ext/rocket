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

#endif//__MYUN2_GITHUB_ROCKET__ROCKET_H__