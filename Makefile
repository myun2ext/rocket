all: win32-http-client-test win32-http-server-test

base:
	gcc -O3 -c rocket.c http.c reciever.c

win32:
	gcc -O3 -c win32.c

win32-http-client-test: base win32
	gcc -O3 http_client_test.c rocket.o http.o win32.o -lws2_32 -o http_client_test.exe
	./http_client_test.exe

win32-http-server-test: base win32
	gcc -O3 http_server_test.c rocket.o http.o win32.o reciever.o -lws2_32 -o http_server_test.exe
	./http_server_test.exe
