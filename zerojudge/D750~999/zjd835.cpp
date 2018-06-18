#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    string r="",s;
    while(cin>>s){
        r+=s;
    }
    a=b=0;
    for(int i=0;i<r.size()-1;i++){
        if(r[i]=='E')break;
        if(r[i]=='W'){
            a++;
        }else{
            b++;
        }
        if((a>=11||b>=11)&&abs(a-b)>=2){
            cout<<a<<':'<<b<<'\n';
            a=b=0;
        }
    }
    cout<<a<<':'<<b<<'\n';
    cout<<'\n';
    a=b=0;
    for(int i=0;i<r.size()-1;i++){
        if(r[i]=='E')break;
        if(r[i]=='W'){
            a++;
        }else{
            b++;
        }
        if((a>=21||b>=21)&&abs(a-b)>=2){
            cout<<a<<':'<<b<<'\n';
            a=b=0;
        }
    }
    cout<<a<<':'<<b<<'\n';
}
