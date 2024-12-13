#include<iostream>
using namespace std;


class Complex{
    int r, img;
public:
    Complex(){
        r = 0; img = 0;
    }

    friend Complex operator + (Complex c1, Complex c2){
        Complex nc;
        nc.r = c1.r + c2.r;
        nc.img = c1.img + c2.img;

        return nc;
    }


    friend ostream &operator << (ostream &out, Complex &c1){
        out<<c1.r<<" + i"<<c1.img<<endl;
        return out;
    }

    friend istream &operator >> (istream &in, Complex &c1){
        in>>c1.r>>c1.img;
        return in;
    }

};

int main( ){
    Complex c1, c2, c3;
    cin>>c1;
    cout<<endl;
    cin>>c2;

    c3 = c1 + c2 ;

    cout<<"C1 :"<<c1;
    cout<<"C2 :"<<c2;
    
    cout<<c3;

    return 0;
}