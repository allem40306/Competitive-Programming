#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    while(cin>>n,n){
        cin>>s;
        n=s.size()/n;
        for(int i=n-1;i<s.size();i+=n){
            for(int j=0;j<n;j++){
                cout<<s[i-j];
            }
        }
        cout<<'\n';
    }
}
