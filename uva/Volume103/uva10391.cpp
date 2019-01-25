#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    set<string>se;
    while(cin>>s){
        se.insert(s);
    }
    for(auto it:se){
        for(int i=0;i<it.size()-1;i++){
            string s1=it.substr(0,i+1);
            string s2=it.substr(i+1,it.size()-(i+1));
            if(se.find(s1)!=se.end()&&se.find(s2)!=se.end()){
                cout<<it<<'\n';
                break;
            }
        }
    }
}