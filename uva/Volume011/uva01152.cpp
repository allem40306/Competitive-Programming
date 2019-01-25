#include <bits/stdc++.h>
using namespace std;
const int N=4005;
int main(){
    int t,n;
    int a[N],b[N],c[N],d[N];
    bool o=false;
    cin>>t;
    while(t--){
        if(o)cout<<'\n';o=true;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i]>>c[i]>>d[i];
        }
        vector<int>v;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v.push_back(a[i]+b[j]);
            }
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=upper_bound(v.begin(),v.end(),-c[i]-d[j])-lower_bound(v.begin(),v.end(),-c[i]-d[j]);
            }
        }
        cout<<ans<<'\n';
    }
}