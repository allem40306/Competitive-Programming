#include <bits/stdc++.h>
using namespace std;
const int N=3005;
int n,a[N],b[N],v[N];

int sol(){
    int ans=0,L,R;
    for(int i=0;i<n;i++){
        L=R=v[a[i]];
        for(int j=i+1;j<n;j++){
            L=min(L,v[a[j]]);
            R=max(R,v[a[j]]);
            if(j-i==R-L)ans++;
        }
    }
    return ans;
}

int main(){
    while(cin>>n,n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            v[b[i]]=i;
        }
        cout<<sol()<<'\n';
    }
}
