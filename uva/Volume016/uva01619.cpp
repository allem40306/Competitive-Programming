#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int n,L[N],R[N];
LL a[N],sum[N];

int main(){
    bool o=false;
    while(cin>>n){
        if(o)cout<<'\n'; o=true;
        sum[0]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
            L[i] = R[i] = 1;
        }
        if(sum[n] == 0){
            cout<<"0\n1 1\n";
            continue;
        }
        stack<int>st;
        for(int i=1;i<=n;i++){
            while(!st.empty()&&a[st.top()]>=a[i])st.pop();
            if(st.empty())L[i]=1;
            else L[i]=st.top()+1;
            st.push(i);
        }
        stack<int>st2;
        for(int i=n;i>=1;i--){
            while(!st2.empty()&&a[st2.top()]>=a[i])st2.pop();
            if(st2.empty())R[i]=n;
            else R[i]=st2.top()-1;
            st2.push(i);
        }
        LL ans=0;
        int ll=0,rr=n;
        for(int i=1;i<=n;i++){
            LL tmp=a[i]*(sum[R[i]]-sum[L[i]-1]);
            // cout<<a[i]<<' '<<L[i]<<' '<<R[i]<<'\n';
            if(tmp>ans||(tmp==ans&&R[i]-L[i]<rr-ll)){
                ans=tmp;
                ll=L[i];
                rr=R[i];
            }
        }
        cout<<ans<<'\n'<<ll<<' '<<rr<<'\n';
    }
}