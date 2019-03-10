#include <bits/stdc++.h>
using namespace std;
map<char,int>tb;

void init(){
    tb['W']=64;
    tb['H']=32;
    tb['Q']=16;
    tb['E']=8;
    tb['S']=4;
    tb['T']=2;
    tb['X']=1;
}

int main(){
    init();
    string s;
    while(cin>>s,s!="*"){
        int t=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='/'){
                ans+=(t==64);
                t=0;
            }else{
                t+=tb[s[i]];
            }
        }
        cout<<ans<<'\n';
    }
}
