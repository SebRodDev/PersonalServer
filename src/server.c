// Personal Web Server to host my personal website

// Start of all of the necessary include -- will be built further on to it

#include <assert.h>
#include <sys/socket.h>

int main() {

    // this server will use an IPv4 address to only have a 32 bit IP address
    // also using IPv4 to implement a personal security feature instead of the
    // IPv6 which has a builtin security feature


    // initializing the socket for the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // ensuring that the socket was correctly initialized
    assert(server_socket != -1);

    struct sockaddr current_address;
    memset(&current_address, 0, sizeof(current_address);

    // binding the socket to an address
    int bounded_server = bind(server_socket,

}
