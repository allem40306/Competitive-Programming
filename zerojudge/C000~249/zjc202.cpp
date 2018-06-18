#include <bits/stdc++.h>
using namespace std;
#define dth(x) int(x<='Z'&&x>='A'?x-'A'+10:x-'0')
int main(){
    long long int ans,n,x;
    cin>>n>>ans;
    n--;
    while(n--){
        cin>>x;
        ans=__gcd(ans,x);
    }
    cout<<ans<<'\n';
}
