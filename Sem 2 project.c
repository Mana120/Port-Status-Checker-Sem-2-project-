#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>


int main() {
    
    int port_number ;
    printf("enter port number: ");
    scanf("%d",&port_number);
    if( port_number>0 && port_number<=65535)
    {
    int socket_file_descriptor;
    
    char *hname ="google.com";
     
    struct sockaddr_in server_address;
    struct hostent *server;
     server = gethostbyname(hname);
     socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);	
    
    
    if (socket_file_descriptor < 0) {
        printf("------------------------\n");
        printf("------------------------\n");
        printf("                        \n");
        printf("Error opening socket\n");
        printf("                        \n");
        printf("------------------------\n");
        printf("------------------------\n");
    }

    
    if (server == NULL) {
        printf("------------------------\n");
        printf("------------------------\n");
        printf("                        \n");
        printf("ERROR:no such host found\n");
        printf("                        \n");
        printf("------------------------\n");
        printf("------------------------\n");
        exit(EXIT_SUCCESS);
    }
    

    server_address.sin_family = AF_INET;
    memmove((char *)&server_address.sin_addr.s_addr,(char *)server->h_addr, server->h_length);

    server_address.sin_port = htons(port_number);
    if (connect(socket_file_descriptor,(struct sockaddr *) &server_address,     sizeof(server_address)) < 0) {
        printf("------------------------\n");
        printf("------------------------\n");
        printf("                        \n");
        printf("    Port is Closed\n");
        printf("                        \n");
        printf("------------------------\n");
        printf("------------------------\n");
    } 
    else {
        printf("------------------------\n");
        printf("------------------------\n");
        printf("                        \n");
        printf("     Port is Open\n");
        printf("                        \n");
        printf("------------------------\n");
        printf("------------------------\n");
        exit(EXIT_SUCCESS);
    }
    printf("Port not opening");
    close(socket_file_descriptor);
    return 0;
    }
    else
    {
        printf("------------------------\n");
        printf("------------------------\n");
        printf("                        \n");
        printf("   INVALID PORT NUMBER\n");
        printf("                        \n");
        printf("------------------------\n");
        printf("------------------------\n");
        return 0;
      }
    
}