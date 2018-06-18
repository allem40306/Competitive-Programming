#include <bits/stdc++.h>
using namespace std;
#define s(n) n*(n+1)/2

int main(){
    int n,ans;
    while(cin>>n){
        ans=0;
        for(int i=1;i<=n;i++){
            ans+=s(i);
            if(i*2<=n){
                ans+=s(int(i*2-1+(n%2)));
            }
        }
        cout<<ans<<'\n';
    }
}
