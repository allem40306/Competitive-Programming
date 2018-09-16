#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
//#define debug
int main(){
    short n,m,a[N],k,x;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    a[n]=-1;
    for(int i=0;i<m;i++){
        cin>>k;
        if(a[k]==-1){
            cout<<"0u0 ...... ?\n";
            #ifdef debug
                printf("%d:%d\n",a[k],a[a[k]]);
            #endif // debug
        }else{
            x=a[k];
            cout<<x<<'\n';
            a[k]=a[x];
            a[x]=-1;
        }
    }
}
