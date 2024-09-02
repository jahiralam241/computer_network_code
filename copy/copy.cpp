#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define BUFSIZE 1024
using namespace std;

int main(int argc, char *argv[]){
    int fd1,fd2,n;
    char buf[BUFSIZ];
    string file1,file2;
     
    fd1=open(argv[1],O_RDONLY);
    fd2=open(argv[2],O_WRONLY | O_CREAT,0644);

    while((n=read(fd1,&buf,BUFSIZ))>0)
          write(fd2,&buf,n);


     close(fd1);
     close(fd2);


   exit(0);

}