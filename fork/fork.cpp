#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>




using namespace std;


int main(){
    int num1,num2,addition,subtraction;
    cout<<"enter two number"<<endl;
    cin>>num1>>num2;

    int pid =fork();



    if(pid==-1){
        cout<<"failed to fork"<<endl;

    }
    else if(pid ==0){
        cout<<"In child process"<<endl;
        subtraction=num1-num2;
        cout<<"subtraction done by chile process  "<<subtraction<<endl;


    }
    else{
        wait(0);
        cout<<"in paresnt processs"<<endl;
        addition =num1+num2;
        cout<<"addition in parent process"<<addition<<endl;

    }



   return 0;

    
}