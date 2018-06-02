#include <bits/stdc++.h>
using namespace std;
const int N=50005;

int main(){
    int n,ans[N]={0,1};
    for(int i=2;i<N;i++){
        ans[i]=ans[i-1]*i;
        while(!(ans[i]%10))ans[i]/=10;
        ans[i]=ans[i]%100000;
    }
    while(cin>>n){
        cout<<setw(5)<<n;
        cout<<" -> "<<ans[n]%10<<'\n';
    }
}
