#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdlib.h>


/* 
 *
 * now the first thing, we will start to build is the socket. 
 * We need to understand what a socket is. A socket is bascially something that
 * enables 2 processes to communicate with each other. This communication could
 * in the same machine(what is called local network) or over the network.
 * To understand this, it is important to know proceses can commicate with each
 * other. They could be through Shared Memory, Pipes(names or anonymous files)
 * message Queues, signals, Memory-Mapped files or sockets.
 *
 *
 */

int main() {
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0) {
		return -1;
	}
	int optval = 1;
	int sockopt = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
	if (sockopt < 0) {
		perror("setsocketopt");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", fd);
	printf("%d\n", sockopt);
	return EXIT_SUCCESS;
}


