#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL gcd(int a,int b){
    if(a<b)swap(a,b);
    LL t;
    while(t=a%b){
        a=b;
        b=t;
    }
    return b;
}

LL lcm(LL a,LL b){
    return a/gcd(a,b)*b;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    LL n,m,a[20],ans,add,r;
    while(cin>>n>>m){
        for(int i=0;i<m;i++){
            cin>>a[i];
        }
        ans=n;
        for(int i=1;i<(1<<m);i++){
            r=0;
            add=1;
            for(int j=0;j<m;j++){
                if(i&(1<<j)){
                    r++;
                    add=lcm(add,a[j]);
                }
            }
            if(r%2){
                ans-=n/add;
            }else{
                ans+=n/add;
            }
        }
        cout<<ans<<'\n';
    }
}
