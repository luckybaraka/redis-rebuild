#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>



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
	//We take in a socket that takes in 3 params, it takes in the domain, type, and protocol, it returns a file descriptor that is going to be positive and if negative, that is an error and has to be handled.
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0) {
		return errno;
	}
	printf("%d\n", fd);
	return 0;
}


