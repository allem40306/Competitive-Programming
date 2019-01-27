#include <bits/stdc++.h>
using namespace std;
const int N=505;
int n;
int a[N],b[N];

void debug(){
    for(int i=1;i<=n;i++)cout<<b[i]<<' ';
    cout<<'\n';
}
int sol(){
    int ret=0;
    for(int i=1;i<=n;i++){
        while(b[i]!=i){
            swap(b[i],b[b[i]]);
            ret++;
        }
    }
    return ret;
}

int main(){
    while(cin>>n,n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int ans=n*n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                b[j+1]=a[(i+j)%n];
            }
            // debug();
            ans=min(ans,sol());
            for(int j=0;j<n;j++){
                b[j+1]=n-a[(i+j)%n]+1;
            }
            // debug();
            ans=min(ans,sol());
        }
        cout<<ans<<'\n';
    }
}