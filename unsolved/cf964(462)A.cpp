#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n,m,x;
    vector<long long>a,b;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<m;i++){
        cin>>x;
        b.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a[n-2]>0)cout<<a[n-2]*b[m-1]<<'\n';
    else cout<<a[n-2]*b[0]<<'\n';
}
