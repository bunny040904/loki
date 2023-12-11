//Implement a class Complex which represents the Complex Number data type. Implement the following operations:
//1. Constructor (including a default constructor which creates the complex number 0+0i).
//2. Overloaded operator+ to add two complex numbers.
//3. Overloaded operator* to multiply two complex numbers.
//4. Overloaded << and >> to print and read Complex Numbers.
//Hint:
//Addition of Complex number is: 
//(a+ib)+(c+id)=(a+c)+i(b+d)

//Multiplication of complex numbers is: 
//(a+ib)(c+id)=(ac-bd)+i(ad+bc).




#include <iostream>
using namespace std;
class complex
{
    public:
    int r,i;
    complex(){
        r=0;
        i=0;
    }
        complex operator +(complex &c)
        {
            complex t;
            t.r=r+c.r;
            t.i=i+c.i;
            return t;
            
        }
        complex operator *(complex &c)
        {
            complex t;
            t.r=(r*c.r)-(i*c.i);
            t.i=(r*c.r)+(i*c.r);
            return t;
        }
        friend ostream & operator<<(ostream &out,complex &c);
        friend istream & operator<<(istream &in,complex &c);
};
istream & operator>>(istream &in,complex &c)
        {
            cout<<"enter the real part:";
            in>>c.r;
            cout<<"enter the imaginary part:";
            in>>c.i;
            return in;
        }
ostream & operator<<(ostream &out,complex &c)
        {
            out<<c.r<<"+"<<c.i<<"i";
            return out;
        }   
int main()
{
    complex c1,c2,c3,c4;
    cout<<"enter the first number"<<endl;
    cin>>c1;
    cout<<"enter the second number"<<endl;
    cin>>c2;
    c3=c1+c2;
    cout<<"addition is:"<<c3<<endl;
    c4=c1*c2;
    cout<<"multiplication is:"<<c4<<endl;
    return 0;
}
