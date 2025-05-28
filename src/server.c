// Personal Web Server to host my personal website

// this server will use an IPv4 address to only have a 32 bit IP address
// also using IPv4 to implement a personal security feature instead of the
// IPv6 which has a builtin security feature

// This server uses assertions when any errors occur during initialization
// Start of all of the necessary include -- will be built further on to it

// FUTURE NOTE: When using a loop to accept connections do not use assertions
// to check to see if the connection was possible

#include <arpa/inet.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT_NUMBER (8000)
#define BACKLOG_VALUE (5)
#define MAX_BUFFER_SIZE (1024)

// global variable for the server socket
int server_socket;
struct sockaddr_in current_address;

void establish_server_socket() {
    // initializing the socket for the server
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // ensuring that the socket was correctly initialized with an assert
    assert(server_fd != -1);

    memset(&current_address, 0, sizeof(current_address));

    // initializing the sockaddr stuct
    current_address.sin_family = AF_INET;
    current_address.sin_port = htons(PORT_NUMBER);

    // Specifying the IP address of the connection that we want to create

    // For our server we will simply use local host for now but eventually
    // change it -- (127.0.0.1 == localhost)
    current_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // binding to a specific port
    int binded_server = bind(server_fd, (struct sockaddr *) &current_address,
                             sizeof(struct sockaddr_in));

    // ensuring that the bind function does not fail
    assert(binded_server != -1);

    server_socket = server_fd;
}

// 200 OK response on initial connection
int send_ok_response() {
    char initial_connection_message[MAX_BUFFER_SIZE] = "200 OK";
    int initial_response = send(server_socket,
                                (void *) initial_connection_message,
                                MAX_BUFFER_SIZE, MSG_CONFIRM);

    if (initial_response == -1) {
        perror("Unable to send initial message\n");
    }

    return initial_response;
}

int main() {

    establish_server_socket();

    // listening for connections
    int listening_bind = listen(server_socket, BACKLOG_VALUE);

    assert(listening_bind != -1);

    printf("listening on port %d\n", PORT_NUMBER);

    // loop to accept connections

    // first focusing on getting one client to work then will implement
    // a loop that allows multiple users to connect

    socklen_t socklen_element = sizeof(struct sockaddr_in);

    // locking accept
    int client_fd = accept(server_socket, (struct sockaddr *) &current_address,
                           &socklen_element);

    assert(client_fd != -1);

    int initial_message = send_ok_response();
}
