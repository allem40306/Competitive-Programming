#include <bits/stdc++.h>
using namespace std;
const int N=50;
int main(){
    int t,n,m,p[N],x;
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(p,0,sizeof(p));
        for(int i=0;i<m;i++){
            for(int i=0;i<n;i++){
                cin>>x;
                if(x==1)p[i]++;
            }
        }
        int ans=1;
        for(int i=0;i<n;i++){
            if(p[i])ans*=p[i];
        }
        cout<<ans<<'\n';
    }
}
