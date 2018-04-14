#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    long long n;
    while(cin>>n,n){
        long long L=1,R,ans=0,t;
        while(L<=n){
            t=n/L;
            R=n/t;
            ans+=t*(L+R)*(R-L+1)/2;
            L=R+1;
        }
        cout<<ans-1<<'\n';
    }
}
