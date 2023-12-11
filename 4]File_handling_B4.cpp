/*
File Handling in c++
Write a C++ program that creates an output file, 
writes information to it, closes the file, 
open it again as an input file and read the information from the file.
*/




#include<iostream>
#include<fstream>
using namespace std;

class employee
{
    public:
    string name;
    int salary;
    int id;
    void accept()
    {
        cout<<"Enter name of employee : ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter ID : ";
        cin>>id;
        cout<<"Enter salary of employee : ";
        cin>>salary;
    }
    
    void display()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"ID : "<<id<<endl;
        cout<<"salary : "<<salary<<endl;
    }
};
int main()
{
    fstream f;
    employee o[10];
    int total,i=0;
    cout<<"Enter total number of employees : ";
    cin>>total;
    cout<<"\nEnter employee information : "<<endl;
    f.open("emp.txt",ios::out);
    while(i<total)
    {
        cout<<"\nEmployee "<<i+1<<" : "<<endl;
        o[i].accept();
        f.write((char *)&o[i],sizeof(o[i]));
        i++;
    }
    f.close();
    f.open("emp.txt",ios::in);
    cout<<endl<<"\nEmployee information : "<<endl;
    i=0;
    while(i<total)
    {
        cout<<"\nEmployee "<<i+1<<" : "<<endl;
        o[i].display();
        f.read((char *)&o[i],sizeof(o[i]));
        i++;
    }
    f.close();
    return 0;
}
