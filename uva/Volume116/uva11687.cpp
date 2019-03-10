#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin>>s,s!="END"){
        if(s.size()==1){
            if(s[0]=='1')cout<<1<<'\n';
            else cout<<2<<'\n';
        }else if(s.size()<10){
            cout<<3<<'\n';
        }else {
            cout<<4<<'\n';
        }
    }
}
