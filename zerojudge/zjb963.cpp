#include <bits/stdc++.h>
using namespace std;
#define sth(x) LL(isalpha(x)?tolower(x)-'a'+10:x-'0')
typedef long long LL;
string t="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

LL th(LL a,string b){
    LL v=0;
    for(int i=0;i<b.size();i++){
        v=v*a+sth(b[i]);
    }
    return v;
}

void ans(LL v,LL b){
    string s="";
    while(v){
        s=t[v%b]+s;
        v/=b;
    }
    cout<<s<<'\n';
}

int main(){
    long long a,val;
    string b;
    while(cin>>a>>b){
        val=th(a,b);
        cin>>a>>b;
        val+=th(a,b);
        cin>>a;
        ans(val,a);
    }
}
