// client handler for connecting to the server as well as communicating with
// the server

#include <arpa/inet.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT (8000)

int main() {

    // get the client fd

    int client_fd = socket(AF_INET, SOCK_STREAM, 0);

    // ensure the client file descriptor was able to be created
    assert(client_fd != -1);

    // creating the connection

    struct sockaddr_in address_information;
    address_information.sin_family = AF_INET;
    address_information.sin_port = htonl(PORT);

    // specifying that we want to listen to a connection on localhost
    address_information.sin_addr.s_addr = inet_addr("127.0.0.1");

    // unsure about this field currently
    socklen_t max_socklen_size = sizeof(struct sockaddr_in);

    // failing at the connection
    int client_connection = connect(client_fd,
                                    (struct sockaddr *) &address_information,
                                    max_socklen_size);

    // asserting that the connection did not fail -- change later
    assert(client_connection != -1);

}
