// Personal Web Server to host my personal website

// This server uses assertions when any errors occur during initialization
// Start of all of the necessary include -- will be built further on to it

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

// global variable for the socket file descriptor
int socket_fd;

int establish_server_socket() {
    // initializing the socket for the server
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // ensuring that the socket was correctly initialized
    assert(server_fd != -1);

    struct sockaddr_in current_address;
    memset(&current_address, 0, sizeof(current_address));

    return 0;
}

int main() {

    // this server will use an IPv4 address to only have a 32 bit IP address
    // also using IPv4 to implement a personal security feature instead of the
    // IPv6 which has a builtin security feature

}
