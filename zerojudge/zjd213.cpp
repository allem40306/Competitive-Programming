#include <iostream>
using namespace std;
const int N=65;
int main(){
    unsigned long long n,dp[N]={2},p=4,r=2;
    for(int i=1;i<N;i++){
        dp[i]=p+dp[i-1];
        if(i>=10){
            dp[i]-=r;
            r*=2;
        }
        p*=2;
    }
    while(cin>>n){
        cout<<dp[n]<<'\n';
    }
}
