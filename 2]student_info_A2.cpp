/*
Personal Information system using constructor, destructor, static member functions, friend class , this pointer 
, inline code and dynamic memory allocation . 
Problem Statement:- Develop a program in C++ to create a database of student's information system containing the following in
formation: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact address, Telephone number, Driving license no. 
and other. Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor,
 destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and 
 delete as well as exception handling.
*/



#include<iostream>
using namespace std;
class student;
class person
{
    private:
        string name,bloodg,caddress,telno,dlno,dob;
    public:
        friend class student;
        person()
        {
            name="";
            bloodg="";
            caddress="";
            telno="";
            dlno="";
            dob="";
        }
        person(const person &p)
        {
            this->name=p.name;
            this->bloodg=p.bloodg;
            this->caddress=p.caddress;
            this->telno=p.telno;
            this->dlno=p.dlno;
            this->dob=p.dob;
        }
};
class student
{
    private:
        int rollno;
        string cls;
        char*div;
        char d;
    public:
        static int count;
        student()
        {
            rollno=0;
            cls="";
            div=NULL;
            count++;
        }
        void acceptstudent(person &p)
        {
            cout<<"\nenter roll number:";
            cin>>rollno;
            cout<<"enter class:";
            cin>>cls;
            cout<<"enter name:";
            cin>>p.name;
            cout<<"enter date of birth:";
            cin>>p.dob;
            cout<<"enter contact number:";
            cin>>p.telno;
            cout<<"enter blood group:";
            cin>>p.bloodg;
            cout<<"enter driving licence no:";
            cin>>p.dlno;
            cout<<"enter living address:";
            cin>>p.caddress;
            cout<<"enter division:";
            cin>>d;
            div=&d;
        }
         inline void dispstudent(person &p)
        {
            cout<<"rollnumber is:"<<rollno<<"|";
            cout<<"class is:"<<cls<<"|";
            cout<<"name is:"<<p.name<<"|";
            cout<<"division is:"<<div<<"|";
            cout<<"birth date is:"<<p.dob<<"|";
            cout<<"phone no is:"<<p.telno<<"|";
            cout<<"blood group is:"<<p.bloodg<<"|";
            cout<<"driving licence no :"<<p.dlno<<"|";
            cout<<"address is :"<<p.caddress<<"|"<<endl;
        }
        ~student()
        {
            delete(div);
        }
        static int getcount()
        {
            return count;
        }
};
int student ::count=0;
int main()
{
    cout<<"Name: Shantanu Prashant Halgaonkar\n";
    cout<<"Roll No: 21\n";
    int ch;
    int n=0;
    person *p[10];
    student *s[10];
    while(1)
    {
        cout<<"enter 1-Enter student |2-Displaying entire database | 0-Exit"<<endl;
        cin>>ch;
        if(ch==1)
        {
            s[n]=new student();
            p[n]=new person();
            s[n]->acceptstudent(*p[n]);
            n++;
        }
        else if(ch==2)
        {
            for(int i=0;i<n;i++)
            {
                s[i]->dispstudent(*p[i]);
            }
            
        }
        else if(ch==0){
            cout<<"exit"<<endl;
            break;
    }
        
    }
}
