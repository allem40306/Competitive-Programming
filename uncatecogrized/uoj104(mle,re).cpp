#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=10005;
const int M=205;
LL n,k,a[N],s[N],q[N];
LL f[M][N],p[M][N],*fptr;

inline LL F(LL i){
    return fptr[i]-s[i]*s[n];
}

inline double slope(LL a,LL b){
    return s[b]==s[a]?-DBL_MAX:(F(a)-F(b))/(s[b]-s[a]);
}

LL sol(){
    LL ans=0,ql,qr;
    for(int i=1;i<k;i++){
        ql=0; qr=-1;
        q[qr++]=i-1;
        for(int j=i;j<n;j++){
            while(qr>ql&&slope(q[ql],q[ql+1])<=s[j])ql++;
            f[i][j]=F(q[ql])+s[j]*(s[n]-s[j]+s[q[ql]]);
            p[i][j]=q[ql];
            ans=max(ans,f[i][j]);
            while(qr-ql&&slope(q[qr],i)<slope(q[qr-1],q[qr]))qr--;
            q[++qr]=i;
        }
    }
    return ans;
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    LL ans=sol();
    cout<<ans<<'\n';
    for(int i=n-1;i>=0;i--){
        if(f[k][i]==ans){
            cout<<i;
            for(int kk=k,pp=p[k][i];kk>1;pp=p[--kk][pp]){
                cout<<' '<<pp;
            }
            cout<<'\n';
            break;
        }
    }
}
