//STL for searching and sorting

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class item{
    public:
    char name[20];
    int qty;
    int cost;
    int code;
    bool operator==(const item&i1){
        if(code==i1.code)
        return 1;
        return 0;
    }
    bool operator<(const item&i1){
        if(code<i1.code)
        return 1;
        return 0;
    }
};
vector<item>obj1;
void print(item &i1);
void display();
void insert();
void search();
void delt();
bool compare(const item &i1,const item &i2){
    return i1.cost<i2.cost;
}
int main(){
    int ch;
    do{
        cout<<"****menu****";
        cout<<"\n1.insert";
        cout<<"\n2.display";
        cout<<"\n3.search";
        cout<<"\n4.sort";
        cout<<"\n5.delete";
        cout<<"\n6.exit";
        cout<<"\nenter your choice:";
        cin>>ch;
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                sort(obj1.begin(),obj1.end(),compare);
                cout<<"\nsorted on cost";
                display();
                break;
            case 5:
                delt();
                break;
            case 6:
                exit(0);
        }
    }while(ch!=7);
    return 0;
}
void insert()
{
    item i1;
    cout<<"\nenter item name:";
    cin>>i1.name;
    cout<<"\nenter quantity:";
    cin>>i1.qty;
    cout<<"\nenter cost:";
    cin>>i1.cost;
    cout<<"\nenter item code:";
    cin>>i1.code;
    obj1.push_back(i1);
}
void display(){
    for_each(obj1.begin(),obj1.end(),print);
}
void print(item &i1){
    cout<<"\nenter item name:"<<i1.name<<endl;
    cout<<"\nenter quantity:"<<i1.qty<<endl;
    cout<<"\nenter cost:"<<i1.cost<<endl;
    cout<<"\nenter item code:"<<i1.code<<endl;
}
void search(){
    vector<item>::iterator p;
    item i1;
    cout<<"\nenter code to search:";
    cin>>i1.code;
    p=find(obj1.begin(),obj1.end(),i1);
    if(p==obj1.end())
    {
        cout<<"\n not found";
    }else{
        cout<<"\nfound"<<endl;
        cout<<"\nenter item name:"<<p->name<<endl;
        cout<<"\nenter quantity:"<<p->qty<<endl;
        cout<<"\nenter cost:"<<p->cost<<endl;
        cout<<"\nenter item code:"<<p->code<<endl;
    }
}
void delt(){
    vector<item>::iterator p;
    item i1;
    cout<<"\nenter code to delete:";
    cin>>i1.code;
    p=find(obj1.begin(),obj1.end(),i1);
    if(p==obj1.end())
    {
        cout<<"\n not found";
    }else{
        obj1.erase(p);
        cout<<"\ndelete";



}
}
