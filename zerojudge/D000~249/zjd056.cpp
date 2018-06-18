#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
short int a[N],x,y;

int main(){
    int n,m;
    cin>>n;
    cin.tie(NULL);
    for(int ni=0;ni<n;ni++){
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            a[i]=x+y;
        }
        for(int i=m-1;i;i--){
            a[i-1]+=a[i]/10;
            a[i]%=10;
        }
        if(ni)cout<<'\n';
        int k=0;
        while(k<m&&!a[k])k++;
        if(k==m)cout<<0;
        for(;k<m;k++){
            cout<<a[k];
        }
        cout<<'\n';
    }
}
