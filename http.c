#include <string.h>
#include "rocket.h"
#include "rocket/http.h"

ROCKET http_rocket(const char* host)
{
	ROCKET rock = tcp_rocket();
	fire_tcp_rocket(rock, host, 80);
	return rock;
}

int get_http_data(const char* host, unsigned short port, const char* path, char* buffer, unsigned int bufsize)
{
	ROCKET rock = tcp_rocket();
	int reserved_size = 0;

	if ( is_invalid_rocket(rock) ){
		return -3;
	}
	if ( fire_tcp_rocket(rock, host, port) != 0 ){
		return -2;
	}

	send(rock, "GET ", 4, 0);
	send(rock, path, strlen(path), 0);
	send(rock, " HTTP/1.1\r\n", 11, 0);
	send(rock, "Host: ", 6, 0);
	send(rock, host, strlen(host), 0);
	send(rock, "\r\n\r\n ", 4, 0);

	reserved_size = recv(rock, buffer, bufsize, 0);
	destroy_rocket(rock);
	return reserved_size;
}
