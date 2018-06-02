#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int main(){
    int t,n,a[N],x,ti=1;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>x;
            a[i]-=x;
        }
        int ans=0,len,tot;
        for(;ans<n;){
            if(a[ans]<0){ans++;continue;}
            tot=a[ans];
            for(len=1;len<n;len++){
                tot+=a[(ans+len)%n];
                if(tot<0)break;
            }
            if(len==n)break;
            ans=ans+len+1;
        }
        cout<<"Case "<<ti++<<": ";
        if(ans>=n){
            cout<<"Not possible\n";
        }else{
            cout<<"Possible from station "<<ans+1<<'\n';
        }
    }
}
