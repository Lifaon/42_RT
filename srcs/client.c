#include "rtv1.h"

void client(t_data *data, char *ip)
{
	SOCKET				sock;
	SOCKADDR_IN			sin;
	int					sock_err;

	/* Création de la socket */
	sock = socket(AF_INET, SOCK_STREAM, 0);

	/* Configuration de la connexion */
	sin.sin_addr.s_addr = inet_addr(ip);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORT);

	/* Si le client arrive à se connecter */
	if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
		printf("Connexion à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
	else
		printf("Impossible de se connecter\n");
	char *buff;
	buff = (char*)malloc(sizeof(char) * ft_strlen("bonjour\n"));
	sock = recv(sock, (char*)buff, sizeof(char) * SOCK_BUFF, 0);
	NL;
	printf("message recu : %s\n", buff);
	NL;
	exit(1);

	/* On ferme la socket précédemment ouverte */
	closesocket(sock);
}
