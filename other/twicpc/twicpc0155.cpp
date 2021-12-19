#include<iostream>
using namespace std;
const int MOD = 998244353;

int main(){
    unsigned long long int n,a=1,b,ans=0;
    cin>>n;
    while(n--){
        cin>>b;
        a=(a*b)%MOD;
        ans=(ans+a)%MOD;
    }
    cout<<ans<<'\n';
}
