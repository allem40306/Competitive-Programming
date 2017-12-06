#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,d,r,m[105],e[105],ans;
    while(cin>>n>>d>>r,n||d||r){
        for(int i=0;i<n;i++){
            cin>>m[i];
        }
        for(int i=0;i<n;i++){
            cin>>e[i];
        }
        sort(m,m+n);
        sort(e,e+n);
        ans=0;
        for(int i=0;i<n;i++){
            if(m[i]+e[n-1-i]-d>0)
                ans+=(m[i]+e[n-1-i]-d)*r;
        }
        cout<<ans<<'\n';
    }
}
