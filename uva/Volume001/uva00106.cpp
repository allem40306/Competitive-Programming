#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
int main(){
    int n,ans1,ans2,a,b,c,aa,bb,cc;
    static bool o[N];
    while(cin>>n){
        ans1=0;
        memset(o,0,sizeof(o));
        for(int i=1;i<1000;i++){
            for(int j=i+1;;j+=2){
                if(__gcd(i,j)!=1)continue;
                a=j*j-i*i;
                b=2*i*j;
                c=j*j+i*i;
                if(c>n)break;
                ans1++;
                aa=a; bb=b; cc=c;
                while(cc<=n){
                    o[aa]=o[bb]=o[cc]=1;
                    aa+=a;
                    bb+=b;
                    cc+=c;
                }
            }
        }
        ans2=n;
        for(int i=0;i<=n;i++){
            ans2-=o[i];
        }
        cout<<ans1<<' '<<ans2<<'\n';
    }
}
