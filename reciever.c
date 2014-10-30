void rocket_reciever(const ROCKET_RECIEVER_SETTINGS* settings)
{
	ROCKET listen_rock = rocket(settings->socket_family, settings->socket_type, settings->protocol);
	listen_rocket(settings->port, settings->max_queing);

	while(1)
		settings->callback(rocket_accept(listen_rock));
}

void tcp_rocket_reciever(const ROCKET_RECIEVER_SETTINGS* settings)
{
	ROCKET listen_rock = rocket(AF_INET, SOCK_STREAM, 0);
	listen_rocket(settings->port, settings->max_queing);

	while(1)
		settings->callback(rocket_accept(listen_rock));
}

void http_rocket_reciever(const ROCKET_RECIEVER_SETTINGS* settings)
{
	ROCKET listen_rock = rocket(AF_INET, SOCK_STREAM, 0);
	listen_rocket(80, settings->max_queing);

	while(1)
		settings->callback(rocket_accept(listen_rock));
}
