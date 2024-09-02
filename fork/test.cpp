#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
using namespace std;
#define BUFSIZE 100

int main( int argc , char *argv[]){



    if(argc !=3){
        cout<<"your command line input should be"<<endl;
        cout<<" outputfile {space} source file path {space } destintion filename"<<endl;
        return 1;

    }
    int fd1,fd2,n;


    char buf[BUFSIZE];

    fd1=open(argv[1],O_RDONLY);
    fd2=open(argv[2],O_WRONLY | O_CREAT ,0644);

    while((n=read(fd1,&buf,BUFSIZ))>0){
        write(fd2,&buf,n);
      cout<<"file coppied"<<endl;
      
    }

    close(fd1);
    close(fd2);


return 0;

}