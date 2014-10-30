#include <stdio.h>
#include "rocket.h"
#include "rocket/http.h"

int main()
{
	char data[2048];
	unsigned int size = get_http_data("www.google.co.jp", 80, "/", data, sizeof(data));

	printf("rocket: %d\n", tcp_rocket());
	printf("Recieved size: %d\n", size);
	printf("%s\n", data);
	return 0;
}
