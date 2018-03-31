#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,ans;
    while(cin>>n){
        ans=0;
        while(n!=1){
            ans++;
            n=(n%2?3*n+1:n/2);
        }
        cout<<ans<<'\n';
    }
}
