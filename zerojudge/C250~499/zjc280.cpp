#include <iostream>
using namespace std;
const int N=82;
int main(){
    unsigned long long dp[N]={0,1,1,2,3};
    for(int i=4;i<N;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    int n;
    cin>>n;
    cout<<dp[n]<<'\n';
}
