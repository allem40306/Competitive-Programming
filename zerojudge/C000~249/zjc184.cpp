#include <bits/stdc++.h>
using namespace std;

int sop(int n){
    int ans=0,i;
    for(i=1;i*i<n;i++){
        if(n%i==0){
            ans+=i+(n/i);
        }
    }
    if(i*i==n)ans+=i;
    return ans-n;
}

int main(){
    int n,v,w,i;
    while(cin>>n,n){
        v=sop(n);
        if(v==n){
            cout<<'='<<v<<'\n';
            continue;
        }
        w=sop(v);
        if(w==n){
            cout<<v<<'\n';
        }else{
            cout<<"0\n";
        }
    }
}
