#include "rocket.h"
#pragma comment(lib, "ws2_32.lib")

WSADATA g_rocket_wsaData = {0};

void rocket_wsa_startup()
{
	WORD wVersionRequested = MAKEWORD(2, 2);
	if ( g_rocket_wsaData.wVersion != 0 ) return;
	WSAStartup(wVersionRequested, &g_rocket_wsaData);
}
