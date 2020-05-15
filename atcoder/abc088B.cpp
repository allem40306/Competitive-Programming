#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a=0,x;
    vector<int>v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(i&1){
            a+=v[i];
        }else{
            a-=v[i];
        }
    }
    cout<<abs(a)<<'\n';
}
