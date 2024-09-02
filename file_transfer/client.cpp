#include<iostream>
#include<cstring>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
using namespace std;


int main(int argc,char *argv[]){
    int cli,fd1,fd2;
    char buffer[255];

    struct sockaddr_in seraddr;

    cli=socket(AF_INET,SOCK_STREAM,0);

    seraddr.sin_family=AF_INET;
    seraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    seraddr.sin_port=htons(9898);

    if(connect(cli,(struct sockaddr*)&seraddr,sizeof(seraddr))<0){
        cout<<"error in connecting"<<endl;

    }
    if(argc >1){
    fd1=open(argv[1],O_RDONLY);
    read(fd1,&buffer,255);
    write(cli,&buffer,255);
    }else{
        read(cli,&buffer,255);
        fd2=open("file_f_server.txt", O_WRONLY | O_CREAT,0644);
        write(fd2,&buffer,255);
        cout<<" file recived from server .saved as filke_f_server.txt"<<endl;
        
    }


    close(cli);
    return 0;


}
