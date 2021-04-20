#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>

void main(int argc, char **argv) {
    if (argc < 2)
        fprintf(stderr, "Usage: %s data(16)\n", *argv), exit(0);
    int len = strlen(argv[1]);
    unsigned long long data = strtoll(argv[1], NULL, 16);
    if (data == 0 || errno != 0)
        err(1, "parse error");

    struct sockaddr_in *s = &data;
    printf("addr =  %s\n", inet_ntoa(s->sin_addr));
    printf("port =  %d\n", s->sin_port);
}
