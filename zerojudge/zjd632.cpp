#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,r;
    int add=0;
    while(cin>>s>>r){
        cout<<s<<'\n'<<r<<'\n';
        for(int i=0;i<=32;i++)cout<<'-';
        cout<<'\n';
        for(int i=31;i>=0;i--){
            add+=int(s[i]-'0')+int(r[i]-'0');
            s[i]=char('0'+(add%2));
            add/=2;
        }
        cout<<s<<'\n';
        cout<<"****End of Data******************\n";
    }
}
