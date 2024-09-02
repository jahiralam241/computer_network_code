#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<cstring>
#include "student.cpp"
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
void database(int clientsocket){
    int i=0,roll;
     map<int ,student> m;
     ifstream ifs;
     student s;
     ifs.open("stu.txt");
     while(ifs>>s){
        m.insert(pair<int,student>(i+1,s));
         i++;
     }
    map<int ,student>::iterator itr;
    read(clientsocket,&roll,sizeof(int));
    cout<<"client ::"<<roll<<std::endl;
    itr=m.find(roll);
    student s1=itr->second;
    int r=s1.get_roll();
    string name1=s1.get_name();
    int mar=s1.get_mark();
    write(clientsocket,&r,sizeof(int));
    int len=name1.length();
    write(clientsocket,&len,sizeof(int));
    write(clientsocket,name1.c_str(),len);
    write(clientsocket,&mar,sizeof(int));
    ifs.close();
}
int main(){
    int serversocket=0,clientsocket=-1;
    struct sockaddr_in serveraddr,clientaddr;
    socklen_t addrsize=sizeof(sockaddr_in);
    create_and_bind(serversocket,serveraddr);
    connectionto(serversocket,clientsocket,clientaddr,addrsize);
    database(clientsocket);
return 0;

}

