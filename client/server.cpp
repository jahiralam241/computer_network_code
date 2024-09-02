#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<cstring>

using namespace std;

void create_and_bind(int &serversocket,sockaddr_in &serveraddr){


    serversocket=socket(AF_INET,SOCK_STREAM,0);
    if(serversocket<0){
        return ;

    }
    

    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr=INADDR_ANY;
    serveraddr.sin_port=htons(9898);


    if(bind(serversocket,(struct sockaddr*) &serveraddr,sizeof(serveraddr))<0){
        cout<<"binding error"<<strerror(errno)<<endl;

        return ;
    }
}

void wait_for_connection(int serversocket,int &clientsocket,sockaddr_in &clientaddr,socklen_t &addrsize){

   if(listen(serversocket,5)<0){
    cout<<"error listning"<<endl;
    return ;

   }
   clientsocket=accept(serversocket,(struct sockaddr*)&clientaddr,&addrsize);
   if(clientsocket<0){
    cout<<"error in accepting clent"<<endl;
    return ;

   }
}
void readdata(int clientsocket){
    char buffer[255];
    memset(buffer,0,sizeof(buffer));
    read(clientsocket,buffer,sizeof(buffer));
    cout<<"messege recive"<<buffer<<endl;

}
void closesocket(int serversocket,int clientsocket){
    close(clientsocket);
    close(serversocket);


}


int main(){

   int serversocket,clientsocket;

    struct sockaddr_in serveraddr,clientaddr;
    socklen_t addrsize=sizeof(sockaddr_in);

    create_and_bind(serversocket,serveraddr);
    wait_for_connection(serversocket,clientsocket,clientaddr,addrsize);
    readdata(clientsocket);
    closesocket(serversocket,clientsocket);
    return 0;







}