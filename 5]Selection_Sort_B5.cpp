#include<iostream>
using namespace std;
template<class T>  //t=template variable,class=keyword,template=keyword
void sel(T a[10],int n)
{
    int i,j,min;
    T temp;  //temp is var of data type T
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min])
            min=j;
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    //display sorted elements
    cout<<"sorted array is:";
    for(i=0;i<n;i++)
    {
        cout<<" "<<a[i]<<" ";
    }
}
int main(){
    int a[10];
    float b[10];
    int i,n;
    cout<<"enter total number of integer elements:";
    cin>>n;
    cout<<"\nenter integer elements:";
    for(i=0;i<n;i++){
        cin>>a[i];
    }   
    sel(a,n);
    cout<<"\nenter total number of float elements:";
    cin>>n;
    cout<<"\nenter float elements:";
    for(i=0;i<n;i++){
        cin>>b[i];
    }   
    sel(b,n);
    
}

