#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int,int>ma;
    unsigned long long ans=0,a,b;
    char ch;
    while(cin>>a>>ch>>b,a||b){
        ma[a]=b;
    }
    while(cin>>a>>ch>>b,a||b){
        if(ma.find(a)!=ma.end()){
            ans+=ma[a]*b;
        }
    }
    cout<<ans<<'\n';
}
