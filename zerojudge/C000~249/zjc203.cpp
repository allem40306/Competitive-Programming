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
    int t,n,v;
    cin>>t;
    while(t--){
        cin>>n;
        v=sop(n);
        if(v<n){
            cout<<"deficient\n";
        }else if(v>n){
            cout<<"abundant\n";
        }else{
            cout<<"perfect\n";
        }
    }
}
