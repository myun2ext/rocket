all: test
test: http-client-test http-server-test

test-win32: win32-http-client-test win32-http-server-test

base:
	gcc -O3 -c rocket.c http.c reciever.c -I./

win32objs:
	gcc -O3 -c win32.c

win32-http-client-test: base win32objs
	gcc -O3 http_client_test.c rocket.o http.o win32.o -lws2_32 -o http_client_test.exe
	./http_client_test.exe

win32-http-server-test: base win32objs
	gcc -O3 http_server_test.c rocket.o http.o win32.o reciever.o -lws2_32 -o http_server_test.exe
	./http_server_test.exe

http-client-test: base
	gcc -O3 http_client_test.c rocket.o http.o -o http_client_test
	./http_client_test

http-server-test: base
	gcc -O3 http_server_test.c rocket.o http.o reciever.o -o http_server_test
	./http_server_test
