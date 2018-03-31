#include <bits/stdc++.h>
using namespace std;
const int N=105;
int main(){
    int ans,t,a[N],ai;
    string s;
    cin>>t>>ws;
    while(t--){
        ans=1; ai=0;
        getline(cin,s);
        stringstream ss(s);
        while(ss>>a[ai])ai++;
        for(int i=0;i<ai;i++){
            for(int j=0;j<i;j++){
                ans=max(ans,__gcd(a[i],a[j]));
            }
        }
        cout<<ans<<'\n';
    }
}
