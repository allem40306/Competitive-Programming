#include <bits/stdc++.h>
using namespace std;
int rs(int a){
    int v=0;
    while(a){
        v=v*10+a%10;
        a/=10;
    }
    return v;
}
int main(){
    int a,b,t;
    cin>>t;
    while(t--){
        cin>>a>>b;
//        cout<<rs(a)+rs(b)<<' ';
        cout<<rs(rs(a)+rs(b))<<'\n';
    }
}
