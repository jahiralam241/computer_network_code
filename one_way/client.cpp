#include<iostream>
#include<unistd.h>
#include<cstring>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
using namespace std;
void create_socket(int &clientsocket,sockaddr_in &serveraddr){
    clientsocket=socket(AF_INET,SOCK_STREAM,0);
    if(clientsocket<0){
        cout<<"error in socket creation"<<endl;
   return ;

    }
}
void connection(int &clientsocket,sockaddr_in &serveraddr){
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    serveraddr.sin_port=htons(9899);

    if(connect(clientsocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0){
        cout<<"error in connecting"<<endl;
        return;
    }
}
void writeto(int clientsocket){
    cout<<"enter what do you want to"<<endl;
    char buffer[255];
    memset(buffer,0,255);
    cin.getline(buffer,50);
    write(clientsocket,buffer,255);
    
}
void closeto(int clientsocket){
    close(clientsocket);

}
int main(){
    int clientsocket;
    struct sockaddr_in serveraddr;
    create_socket(clientsocket,serveraddr);
    connection(clientsocket,serveraddr);
    writeto(clientsocket);
    return 0;
}
