#include<iostream>
using namespace std;

class Pub{
    char title[20];
    float price;
public:
    Pub(){
        title[0] = '\0';
        price = 100;
    }
};

class Book: public Pub{
    int page;
public:
    Book() {
        page = 20;
    }
    void in_page() {
        cout<<"Enter page count for your book";cin>>page;
    }
    void display(){

        try{
            if (page < 20) {
                throw 1;
            }
            cout<<page<<endl;
        }
        catch(int i){
            cout<<"Invalid page count"<< "Error"<<" : "<<i<<endl;
            cout<<"Setting page count to 0"<<endl; page = 0;
            cout<<"Page count = "<<page<<endl;
        }
        
    }
};

int main() {
    Book b;
    b.in_page();
    b.display();


    return 0;
}