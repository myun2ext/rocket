#include <stdio.h>
#include "rocket.h"

void rocket_reciever(const ROCKET_RECIEVER_SETTINGS* settings)
{
	struct sockaddr from_addr;
	int from_addr_len;
	ROCKET rock = rocket(settings->socket_family, settings->socket_type, settings->protocol);
	ROCKET accepted_rock;
	listen_rocket(rock, settings->port, settings->max_queing);

	while(1)
	{
		accepted_rock = accept(rock, &from_addr, &from_addr_len);
		settings->callback(accepted_rock, &from_addr, from_addr_len);
	}
}

void tcp_rocket_reciever(ROCKET_RECIEVER_SETTINGS* settings)
{
	settings->socket_family = AF_INET;
	settings->socket_type = SOCK_STREAM;
	settings->protocol = 0;
	rocket_reciever(settings);
}
