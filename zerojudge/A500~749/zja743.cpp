#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    map<string,int>tb;
    map<string,int>::iterator it;
    string s;
    while(cin>>n){
        cin>>ws;
        tb.clear();
        for(int i=0;i<n;i++){
            getline(cin,s);
            stringstream ss(s);
            ss>>s;
            if(tb.find(s)==tb.end()){
                tb[s]=1;
            }else{
                tb[s]++;
            }
        }
        for(it=tb.begin();it!=tb.end();it++){
            cout<<it->first<<' '<<it->second<<'\n';
        }
    }
}
