void rocket_reciever(const ROCKET_RECIEVER_SETTINGS* settings)
{
	ROCKET rock = rocket();
	rocket_bind(rock, settings->port);
	rocket_listen(rock, settings->max_connections);

	while (1)
		settings->callback(rocket_accept(sock));
}
