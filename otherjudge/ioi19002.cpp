#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n>1000)
            cout<<1000<<' '<<n-1000<<'\n';
        else
            cout<<0<<' '<<n-0<<'\n';
    }
}