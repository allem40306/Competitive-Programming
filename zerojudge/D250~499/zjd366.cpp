#include <bits/stdc++.h>
using namespace std;

int calc_v(int x){
    int v=0,i;
    for(i=1;i*i<x;i++){
        v+=2*(x%i==0);
    }
    return v+(i*i==v);
}

int main(){
    int n,a,b,ans,ansv,v;
    cin>>n;
    while(n--){
        ansv=0;
        cin>>a>>b;
        for(int i=a;i<=b;i++){
            v=calc_v(i);
            if(ansv<v){
                ansv=v;
                ans=i;
            }
        }
        cout<<"Between "<<a<<" and "<<b<<", "<<ans<<" has a maximum of "<<ansv<<" divisors.\n";
    }
}
