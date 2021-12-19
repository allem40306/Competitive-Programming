#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    long long n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        n-=2*k+1;
        if(n>=0&&n%(k+1)==0)cout<<"Second\n";
        else cout<<"First\n";
    }
}