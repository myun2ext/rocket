#include <stdio.h>
#include "rocket.h"
#include "rocket/http.h"

void service(ROCKET rock, const struct sockaddr *from_addr, int from_addr_len)
{
	char work[256];
	recv(rock, work, sizeof(work), 0);
	printf("%s\n", work);

	send(rock, "HTTP/1.1 200 OK\n", 16, 0);
	send(rock, "Content-Length: 49\n", 18, 0);
	send(rock, "Content-Type: text/html\n\n", 25, 0);

	send(rock, "<html><head><head><body>Hello world!<body></html>", 49, 0);

	shutdown(rock, 2);
	destroy_rocket(rock);
};

int main()
{
	ROCKET_RECIEVER_SETTINGS settings;
	settings.port = 8080;
	settings.max_queing = 30000;
	settings.callback = service;
	tcp_rocket_reciever(&settings);
}
