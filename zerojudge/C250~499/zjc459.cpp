#include <bits/stdc++.h>
using namespace std;
int p(int x,int y){
    int v=1;
    for(int i=0;i<y;i++){
        v*=x;
    }
    return v;
}
int main(){
    int n,v1=0,v2=0;
    string s;
    cin>>n>>s;
    for(int i=0;i<s.size();i++){
        v1=v1*n+(s[i]-'0');
        v2=v2+p(int(s[i]-'0'),int(s.size()));
    }
    if(v1==v2){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}
