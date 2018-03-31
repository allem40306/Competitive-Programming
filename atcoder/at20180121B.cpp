#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    double n=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        n=n*10+(s[i]-'0');
    }
    cin>>s;
    for(int i=0;i<s.size();i++){
        n=n*10+(s[i]-'0');
    }
    if(sqrt(n)==floor(sqrt(n))){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}
