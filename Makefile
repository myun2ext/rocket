all: win32-http-client-test win32-http-server-test

win32:
	gcc -O3 -c rocket.c http.c

win32-http-client-test: win32
	gcc -O3 http_client_test.c rocket.o http.o -lws2_32 -o http_client_test.exe
	./http_client_test.exe

win32-http-server-test: win32
	gcc -O3 http_server_test.c rocket.o http.o -lws2_32 -o http_server_test.exe
	./http_server_test.exe
