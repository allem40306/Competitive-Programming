#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long x;
    bool o;
    while(cin>>x,x){
        o=0;
        for(long long i=9;i>=0;i--){
            if((10*x-i)%9)continue;
            if(o)cout<<' ';
            o=1;
            cout<<(10*x-i)/9;
        }
        cout<<'\n';
    }
}
