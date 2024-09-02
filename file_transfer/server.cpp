#include<iostream>
#include<cstring>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>

using namespace std;


int main(int argc,char *argv[]){
    int cli,ser,fd1,n,fd2;


    char buffer[255];

    struct sockaddr_in seraddr,cliaddr;
    socklen_t size;

    ser=socket(AF_INET,SOCK_STREAM,0);
    seraddr.sin_family=AF_INET;
    seraddr.sin_addr.s_addr=INADDR_ANY;
    seraddr.sin_port=htons(9898);

    if(bind(ser,(struct sockaddr*)&seraddr,sizeof(seraddr))<0){
        cout<<"error in binding"<<endl;
        exit(1);

        
    }
    if(listen(ser,5)<0){
        cout<<"error in listenning"<<endl;

    }
    cli=accept(ser,(struct sockaddr*)&cliaddr,&size);
    if(cli<0){
        cout<<"error in connecting"<<endl;

    }
    if(argc >1){
    fd2=open(argv[1],O_RDONLY);
    read(fd2,&buffer,255);
    write(cli,&buffer,255);
    }
    else{

    read(cli,&buffer,255);
    fd1=open("file_f_client.txt",O_WRONLY|O_CREAT,0644);
    n= write(fd1,&buffer,255);
         if(n<0){
              cout<<"not success full"<<endl;
         }else{
              cout<<"<<file reciverd .saved as (file_f_client.txt)"<<endl;
         }
    }
    close(cli);
    close(ser);

    return 0;

}