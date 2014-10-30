#include <stdio.h>
#include "rocket.h"
#include "rocket/http.h"

int main()
{
	char data[2048];
	unsigned int size = get_http_data("127.0.0.1", 8080, "/", data, sizeof(data));

	printf("Recieved size: %d\n", size);
	printf("%s\n", data);
	return 0;
}
