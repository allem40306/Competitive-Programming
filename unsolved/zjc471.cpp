#include <bits/stdc++.h>
using namespace std;
const int N=100005;
struct node{
    int w,t;
    node(){};
    node(int w,int t):w(w),t(t){}
    bool operator <(const node&b){
        if(w!=b.w)return w>b.w;
        return t>b.t;
    }
};
int main(){
    int n;
    cin>>n;
    node a[N];
    for(int i=0;i<n;i++){
        cin>>a[i].w;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].t;
    }
    sort(a,a+n);
    long long ans=0,cw=a[0].w;
    for(int i=1;i<n;i++){
        ans+=a[i].t*cw;
        cw+=a[i].w;
    }
    cout<<ans<<'\n';
}
