#include<bits/stdc++.h>
#include"Hashmap_implementation.h"
using namespace std;
int main(){
    ourmap<int> map;
    for (int i = 0; i < 20; i++)
    {
        char c='0'+i;
        string key="abc";
        key=key+c;
        int value=i+1;
        map.insert(key, value);
        // cout<<"Size of map:"<<map.size()<<endl;
        // cout<<"Load Factor of map:"<<map.getLoadFactor()<<endl;
    }
    cout<<"size:"<<map.size()<<endl;
    map.remove("abc2");
    map.remove("abc3");
    cout<<"Size:"<<map.size()<<endl;
    for (int i = 0; i < 20; i++)
    {
        char c='0'+i;
        string key="abc";
        key=key+c;
        cout<<key<<":"<<map.getValue(key)<<endl;

    }
    
    
    
}