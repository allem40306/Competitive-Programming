#include <bits/stdc++.h>
using namespace std;
const int N=100005;
struct node{
    int l,r,m;
    node(){};
    node(int l,int r,int m):l(l),r(r),m(m){}
    bool operator <(const node& b)const{
        if(r!=b.r)return r<b.r;
        if(l!=b.l)return l<b.l;
        return m>b.m;
    }
};
int main(){
    int t,n;
    cin>>t;
    node a[N];
    int dp[N];
    while(t--){
        cin>>n;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            cin>>a[i].l>>a[i].r>>a[i].m;
        }
        sort(a,a+n);
        for(int i=0,j=0;i<N&&j<n;i++){
            while(j<n&&i==a[j].r){
                dp[a[j].r]=max(dp[a[j].r],dp[a[j].l]+a[j].m);
                j++;
            }
            dp[i]=*max_element(dp,dp+i+1);
        }
        cout<<*max_element(dp,dp+N)<<'\n';
    }
}
