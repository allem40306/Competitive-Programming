#include <bits/stdc++.h>
using namespace std;
const int N=100005;
//#define debug
int main(){
    int t,n,ans,a[2][N];
    cin>>t;
    for(int ti=1;ti<=t;ti++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i%2][i/2];
        }
        sort(a[0],a[0]+n/2+(n%2));
        sort(a[1],a[1]+n/2);
        ans=-1;
        for(int i=0;i+1<n;i++){
            #ifdef debug
                printf("%d %d %d\n",i,a[i%2][i/2],a[(i+1)%2][(i+1)/2]);
            #endif // debug
            if(a[i%2][i/2]>a[(i+1)%2][(i+1)/2]){
                ans=i;
                break;
            }
        }
        cout<<"Case #"<<ti<<": ";
        if(ans==-1){
            cout<<"OK\n";
        }else{
            cout<<ans<<'\n';
        }
    }
}
