#ifndef CLUST_H
# define CLUST_H

# include <sys/socket.h>
# include <sys/types.h>
# include <netdb.h>
# include <ifaddrs.h>
# include <netinet/in.h>
# include <arpa/inet.h>

# define closesocket(param) close(param)
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define PORT 15863
# define SOCK_BUFF 50

void			init_host(void);
void			init_client(char *ip);
void			host_work(int send);
void			client_work(void);
int				send_data(int socket, int client);
int				send_data_to_client(void);

#endif
