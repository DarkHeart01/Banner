#include<iostream>
#include<fstream>
using namespace std;

class Student{
    char name[10];
    int age;
public:
    Student(){
        age = 0;
        name[0] = '\0';
    }

    friend ostream &operator <<(ostream &out, Student& s){
        out<<s.age<<s.name<<endl;
        return out;
    } 

    friend istream &operator >>(istream& in, Student& s){
        in>>s.age>>s.name;
        return in;
    }
};

int main(){

   Student p;
    ofstream os("files_formatted.txt");
    char ch = 'y';
    
    do{
        cout<<"Enter details: "<<endl;
        cin>>p;
        os<<p;

        cout<<"Enter choice: ";
        cin>>ch;


    }while(ch == 'y');
    os.close();

    ifstream read("files_formatted.txt");
    cout<<"\nDetails in File: "<<endl;
    while(!read.eof()){
        read >> p;

        if(read.eof()) break;

        cout<<p;
    }
    read.close();

    return 0;
}