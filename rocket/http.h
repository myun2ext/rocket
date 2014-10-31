#ifndef __MYUN2_GITHUB_ROCKET__ROCKET_HTTP_H__
#define __MYUN2_GITHUB_ROCKET__ROCKET_HTTP_H__

ROCKET http_rocket(const char* host);
int get_http_data(const char* host, unsigned short port, const char* path, char* buffer, unsigned int bufsize);

#endif//__MYUN2_GITHUB_ROCKET__ROCKET_HTTP_H__