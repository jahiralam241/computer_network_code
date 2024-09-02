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
    serveraddr.sin_addr.s_addr=inet_addr("127.0.0.9");
    serveraddr.sin_port=htons(9899);


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
    int n,roll,marks;
    string name;
    cout<<"enter roll number to fetch the data"<<endl;
     cin>>n;
     write(clientsocket,&n,sizeof(int));
     read(clientsocket,&roll,sizeof(int));
     int len=0;
     read(clientsocket,&len,sizeof(int));
     name.resize(len);
     read(clientsocket,&name[0],len);
     read(clientsocket,&marks,sizeof(int));
     cout<<" server  :: student name "<<name<<" \n roll no: "<<roll<<" \n marks :"<<marks<<endl;
    return 0;
    


}