#include <iostream>
#include <string>

#include "server.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <poll.h>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;

    std::cout << "hello world" << std::endl;

    int domain = 0; 
    //  The  domain  argument specifies a communication domain; this selects the protocol family which will be used for communication
    int type = 0;
    //The  socket  has  the indicated type, which specifies the communication semantics.
    int protocol = 0;
    /*   The  protocol  specifies a particular protocol to be used with the socket.  Normally only a single protocol
       exists to support a particular socket type within a given protocol family, in which case  protocol  can  be
       specified as 0.  However, it is possible that many protocols may exist, in which case a particular protocol
       must be specified in this manner.  The protocol number to use is specific to the “communication domain”  in
       which  communication  is  to  take place; see protocols(5).  See getprotoent(3) on how to map protocol name
       strings to protocol numbers.
    */
    int fd = socket(domain, type, protocol);



    int level = 0;
    int optname = 0;
    const void * optval;
    socklen_t optlen;
    /* getsockopt()  and setsockopt() manipulate options for the socket referred to by the file descriptor sockfd.  Options may exist at
       multiple protocol levels; they are always present at the uppermost socket level.
    */
    setsockopt(fd , level, optname, optval , optlen);

    //getsockname()
    //getprotobyname();
    //gethostbyname();
    //getaddrinfo();
    //freeaddrinfo();
    //bind();
    //connect();
    //listen();
    //accept();
    //htons(); //convert values between host and network byte order
    //htonl(); 
    //ntohs();
    //ntohl();
    //inet_addr(); function  converts the Internet host address cp from IPv4 numbers-and-dots notation into binary data in network byte order.
    //inet_ntoa();

    //send(); ~= write
    //recv(); ~= read
    //signal();
    //lseek();
    //fstat();
    //fcntl();
    //poll();
    //select();

    return (0);
}