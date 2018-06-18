#include <bits/stdc++.h>
using namespace std;
const int N=10005;
int main(){
    int n;
    cin>>n;
    int *a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=a[n-2]-a[n-1],mn=a[n-1];
    for(int i=n-1;i>=0;i--){
        ans=max(ans,a[i]-mn);
        mn=min(a[i],mn);
    }
    cout<<ans<<'\n';
    free(a);
}
