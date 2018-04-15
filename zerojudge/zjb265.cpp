#include <bits/stdc++.h>
using namespace std;
const int N=10005;
int main(){
    int n,c[N],maxc,ans;
    array<int,5>a[N];
    while(cin>>n,n){
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin>>a[i][j];
            }
            sort(a[i].begin(),a[i].end());
        }
        sort(a,a+n);
        memset(c,0,sizeof(c));
        maxc=c[0]=1;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]){
                c[i]=c[i-1]+1;
            }else{
                c[i]=1;
            }
            maxc=max(maxc,c[i]);
        }
        ans=0;
        for(int i=0;i<n;i++){
            if(c[i]==maxc){
                ans+=maxc;
            }
        }
        cout<<ans<<'\n';
    }
}