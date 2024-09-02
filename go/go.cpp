#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;


int main(){
   int total,win;
   cout<<"total "<<endl;
   cin>>total;
   cout<<"window size"<<endl;
   cin>>win;

   srand(time(NULL));
  int  current=0;


    while(current<=total){
        int suc=0;
        for(int j=current;j<current+win && j<=total;j++){
            cout<<"seding  frane "<<j<<endl;

        }
        for(int j=current;j<current+win && j<=total;j++){
            int ack=rand()%2;
            if(ack){
                cout<<" ack recived for frame"<<j<<endl;
                suc++;

            }else{
                cout<<" frame"<<j <<" lost "<<endl;
                break;

            }
        }
        current+=suc;
        cout<<endl;

    }
    return 0;

  }