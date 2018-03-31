#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,r;
    map<string,int>tb;
    priority_queue<string>q;
    cin>>s;
    tb[s]=1;
    bool o=0;
    for(int i=1;i<=s.size();i++){
        if(s.size()%i)continue;
        r="";
        for(int j=0;j<s.size();j+=i){
            q.push(s.substr(j,i));
        }
        while(!q.empty()){
            r=q.top()+r;
            q.pop();
        }
        if(!tb.count(r)){
            cout<<r<<'\n';
            tb[r]=1;
            o=1;
        }
    }
    if(!o)cout<<"bomb!\n";
}
