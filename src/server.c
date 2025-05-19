// Personal Web Server to host my personal website

// This server uses assertions when any errors occur during initialization
// Start of all of the necessary include -- will be built further on to it

#include <assert.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

// global variable for the socket file descriptor

void establish_server_socket() {
    // initializing the socket for the server
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // ensuring that the socket was correctly initialized with an assert
    assert(server_fd != -1);

    struct sockaddr_in current_address;
    memset(&current_address, 0, sizeof(current_address));

    // initializing the sockaddr stuct
    current_address.sin_family = AF_INET;
    current_address.sin_port = htons(8000);

    // binding to a specific port
    int binded_server = bind(server_fd, (struct sockaddr *) &current_address,
                             sizeof(struct sockaddr_in));

    // ensuring that the bind function does not fail
    assert(binded_server != -1);
}

int main() {

    // this server will use an IPv4 address to only have a 32 bit IP address
    // also using IPv4 to implement a personal security feature instead of the
    // IPv6 which has a builtin security feature

    // listen then accept each connection then send information from client to
    // server

}
