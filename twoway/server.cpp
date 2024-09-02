#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<cstring>


using namespace std;

void create_and_bind(int &serversocket,sockaddr_in &serveraddr){
    serversocket=socket(AF_INET,SOCK_STREAM,0);
    if(serversocket<0){
        cout<<"Error creating socket"<<endl;
        return ;

    }

    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr=INADDR_ANY;
    serveraddr.sin_port=htons(9899);

    if(bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0){
        cout<<"error binding"<<endl;
        return ;

    }
}

void connectionto(int serversocket,int &clientsocket,sockaddr_in &clientaddr,socklen_t &addrsize){
    
   if(listen(serversocket,10)<0){
    cout<<"error listning"<<endl;
    perror("listen");

    return ;

   }
    clientsocket=accept(serversocket,(struct sockaddr*)&clientaddr,&addrsize);
    if(clientsocket<0){
        cout<<"erroe in accepting"<<endl;
        return ;

    }


}

void writeto(int clientsocket){
    char buffer[255];
    memset(buffer,0,sizeof(buffer));

    cin.getline(buffer,50);

    write(clientsocket,buffer,sizeof(buffer));

}
void readto(int clientsocket){
    char buffer[255];

    while(true){
    memset(buffer,0,sizeof(buffer));
    read(clientsocket,buffer,sizeof(buffer));
    if(strcmp("bye",buffer)==0){
        cout<<" bye thank you for contacting"<<endl;
        
        break;
    }

    cout<<"client "<<buffer<<endl;
    writeto(clientsocket);
 

    }
}

void closesocket(int &clientsocket,int &serversocket){
    close(clientsocket);
    close(serversocket);
    
}
int main(){
    int serversocket=0,clientsocket=-1;

    struct sockaddr_in serveraddr,clientaddr;
    socklen_t addrsize=sizeof(sockaddr_in);
    create_and_bind(serversocket,serveraddr);
    connectionto(serversocket,clientsocket,clientaddr,addrsize);
    
    readto(clientsocket);
    
    closesocket(clientsocket,serversocket);
     
return 0;

}


