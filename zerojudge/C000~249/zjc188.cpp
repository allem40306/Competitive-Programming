#include <bits/stdc++.h>
using namespace std;
const int N=205;
int main(){
    long long dp[N]={1};
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j++){
            dp[j]+=dp[j-i];
        }
    }
    int n;
    while(cin>>n){
        cout<<dp[n]<<'\n';
    }
}
