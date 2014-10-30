#include <stdio.h>
#include "rocket.h"
#include "rocket/http.h"

void service(ROCKET rock, const struct sockaddr *from_addr, int from_addr_len)
{
	char work[256];
	recv(rock, work, sizeof(work), 0);
	printf("%s\n", work);
};

int main()
{
	ROCKET_RECIEVER_SETTINGS settings;
	settings.port = 8080;
	settings.max_queing = 3;
	settings.callback = service;
	tcp_rocket_reciever(&settings);
}
