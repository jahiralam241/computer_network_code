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
    serveraddr.sin_port=htons(9898);


    if(connect(clientsocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0){
        cout<<"error in connecting"<<endl;
        return;

    }


}


int main(){
    int clientsocket;
    struct sockaddr_in serveraddr;
    create_socket(clientsocket,serveraddr);
    connection(clientsocket,serveraddr);
   
    int num1,num2,ans,choice,n;
    char buffer[255];
    do{
     memset(buffer,0,255);
     read(clientsocket,buffer,255);
     cout<<"server "<<buffer<<endl;
     cin>>num1;
     write(clientsocket,&num1,sizeof(int));

    
     memset(buffer,0,255);
     read(clientsocket,buffer,255);
     cout<<"server "<<buffer<<endl;
     cin>>num2;
     write(clientsocket,&num2,sizeof(int));

     memset(buffer,0,255);
     read(clientsocket,buffer,255);
     cout<<"server "<<buffer<<endl;
     cin>>choice;
     write(clientsocket,&choice,sizeof(int));

    
     read(clientsocket,&ans,sizeof(int));
     cout<<" server ans is "<<ans<<endl;
     
    }while(choice !=3);
    return 0;
    


}