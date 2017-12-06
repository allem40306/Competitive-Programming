#include <bits/stdc++.h>
using namespace std;
const int N=20005;

int main(){
    int n,m,a[N],b[N],ar,br,ans;
    while(cin>>n>>m,n||m){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+m);
        for(ans=ar=br=0;ar<n&&br<m;ar++){
            while(br<m&&b[br]<a[ar])br++;
            if(br==m)break;
            ans+=b[br]; br++;
        }
        if(ar==n)cout<<ans<<'\n';
        else cout<<"Loowater is doomed!\n";
    }
}
