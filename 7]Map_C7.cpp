//Map Associative container


#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    typedef map<string,int>mapType;
    mapType populationMap;
    populationMap.insert(pair<string,int>("maharashtra",7025697));
    populationMap.insert(pair<string,int>("rajsthan",6578936));
    populationMap.insert(pair<string,int>("karnatka",6678993));
    populationMap.insert(pair<string,int>("punjab",5789037));
    populationMap.insert(pair<string,int>("west bangal",6676291));
    mapType::iterator iter;
    cout<<"**********population of set india***************";
    cout<<"\n size of population map"<<populationMap.size()<<"n";
    string state;
    cout<<"\n enter name of state:";
    cin>>state;
    iter=populationMap.find(state);
    if(iter!=populationMap.end())
    cout<<state<<"  population is "<<iter->second;
    else
    cout<<"key is not population map"<<"\n";
    populationMap.clear();

}
