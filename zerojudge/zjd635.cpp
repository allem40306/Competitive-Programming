#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s="";
    while(cin>>n,n>=0){
        if(!n){
            cout<<"0\n";
            continue;
        }
        s="";
        while(n){
            s=char(n%8+'0')+s;
            n/=8;
        }
        cout<<s<<'\n';
    }
    cout<<"-1\n";
}
