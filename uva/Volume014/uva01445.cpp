#include <bits/stdc++.h>
using namespace std;
const int N=25;

int main(){
    int w,d,a[N],b[N],ans,x;
    while(cin>>w>>d,w||d){
        ans=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<w;i++){
            cin>>x;
            a[x]++;
        }
        for(int i=0;i<d;i++){
            cin>>x;
            b[x]++;
        }
        for(int i=0;i<N;i++){
            ans+=i*max(a[i],b[i]);
        }
        cout<<ans<<'\n';
    }
}
