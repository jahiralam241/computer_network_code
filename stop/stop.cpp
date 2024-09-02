#include<iostream>
using namespace std;

void reciver(int frame){
    cout<<" reciver : frame recived"<<endl;

}
int main(){
    int totalframe,frametosend=1,ack;


    cout<<"enter how many frame want to send"<<endl;
    cin>>totalframe;

    
    while(frametosend<=totalframe){
        cout<<" serder :  sending frame no "<<frametosend<<endl;
        cout<<" ack frame  for 1  and 0 for not"<<endl;
        cin>>ack;
        
        if(ack==1){
            reciver(frametosend);
            frametosend++;

        }



    }
    return 0;
    
}