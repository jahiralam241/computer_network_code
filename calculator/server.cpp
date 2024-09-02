#include<iostream>
#include<cstring>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
using namespace std;

void create_and_bind(int &serversock,sockaddr_in  &serveraddr){
    serversock=socket(AF_INET,SOCK_STREAM,0);
    if(serversock<0){
        cout<<"ERROR socket creation"<<endl;
        return ;   
    }
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr=INADDR_ANY;
    serveraddr.sin_port=htons(9898);

    if(bind(serversock,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0){
        cout<<"ERROR in binding"<<endl;
        return;

    }
}

void connection(int serversock,int &clientsock,sockaddr_in &clientaddr,socklen_t &size){
    if(listen(serversock,5)<0){
        cout<<"ERROR in listing"<<endl;
        return ;    
    }
    clientsock=accept(serversock,(struct sockaddr*)&clientaddr,&size);
    if(clientsock<0){
        cout<<"ERROR in acccepting"<<endl;
        return;

    }
}

int main(){
    int serversock,clientsock;
    struct sockaddr_in serveraddr,clientaddr;
    socklen_t size;

    create_and_bind(serversock,serveraddr);
    connection(serversock,clientsock,clientaddr,size);
    
    int num1,num2,ans,choice,n;

do{
   n=write(clientsock,"enter number 1",strlen("enter number 1"));
   if(n<0){
    cout<<"erroor in writing "<<endl;

   }
   read(clientsock,&num1,sizeof(int));
   cout<<"client num1 is ::"<<num1<<std::endl;


   n=write(clientsock,"enter number 2",strlen("enter number 2"));
   read(clientsock,&num2,sizeof(int));
   cout<<"client num2 is ::"<<num2<<std::endl;


   n=write(clientsock,"1.add 2.sub",strlen("1.add 2.sub"));
   read(clientsock,&choice,sizeof(int));
   cout<<"choice :"<<choice<<std::endl;
   


   switch(choice){
    case 1:
          ans=num1+num2;
          break;
    case 2:
        ans=num1-num2;
        break;
    case 3:
         break;

  
   }
   write(clientsock,&ans,sizeof(int));


}while(choice !=3);
    return 0;
    
}

