#include<iostream>
#include<cstring>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

using namespace std;
void createsocket(int &clientsocket,sockaddr_in &serveraddr){
    clientsocket=socket(AF_INET,SOCK_STREAM,0);
    if(clientsocket<0){
        cout<<"error creating socket"<<endl;
        return ;

    }
}
void connection(int &clientsocket,sockaddr_in &serveraddr){
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    serveraddr.sin_port=htons(9898);

    if(connect(clientsocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0){
        cout<<"error connecting"<<endl;
        return ;

    }
}

void writeto(int clientsocket){
          char buffer[255];
          strcpy(buffer,"hello i from clent");
          write(clientsocket,buffer,sizeof(buffer));

}
void closeto(int clientsocket){
    close(clientsocket);

}
int main(){
    int clientsocket;
    struct sockaddr_in serveraddr;
    createsocket(clientsocket,serveraddr);
    connection(clientsocket,serveraddr);
    writeto(clientsocket);
    closeto(clientsocket);
    return 0;



}