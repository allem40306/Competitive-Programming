#include <bits/stdc++.h>
using namespace std;
void xth(string s){
    int o=0;
    for(int i=2;i<s.size();i++){
        o=o*16+((s[i]<='9'&&s[i]>='0')?s[i]-'0':(s[i]-'A')+10);
    }
    cout<<o<<'\n';
}
void htx(string s){
    int n=0;
    for(int i=0;i<s.size();i++){
        n=n*10+(s[i]-'0');
    }
    string r;
    while(n){
        r=(n%16>9?char(n%16-10+'A'):char(n%16+'0'))+r;
        n/=16;
    }
    cout<<"0x"<<r<<'\n';
}
int main(){
    string s;
    while(cin>>s,s[0]!='-'){
        if(s.size()>=2&&s[0]=='0'&&s[1]=='x'){
            xth(s);
        }else{
            htx(s);
        }
    }
}
