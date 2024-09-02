#include<iostream>
#include<fstream>
#include<map>
using namespace std;
class student{
    private:
         int roll;
         string name;
         int marks;
    public:
         student(){}
         student(int n,string nam,int m){
            roll=n;
            name=nam;
            marks=m;
         }
         void set_roll(int r){
            roll=r;

         }
         void set_name(string nam){
            name=nam;

         }
         void set_marks(int mark){
            marks=mark;

         }
         int get_roll(){return roll;}
         string get_name(){return name;}
         int get_mark(){return marks;}

friend ofstream &operator<<(ofstream &file,student &a);
friend ifstream &operator>>(ifstream &file,student &a);
friend ostream &operator<<(ostream &os ,student &a);
};


ofstream &operator<<(ofstream &file,student &a){
    file<<a.roll<<endl;
    file<<a.name<<endl;
    file<<a.marks<<endl;
    return file;

}
ifstream &operator>>(ifstream &file,student &a){
    file>>a.roll>>a.name>>a.marks;
     return file;

}
ostream &operator<<(ostream &os,student &a){
    os<<"roll number"<<a.roll<<endl;
    os<<"name"<<a.name<<endl;
    os<<"marks"<<a.marks<<endl;
    return os;

}
