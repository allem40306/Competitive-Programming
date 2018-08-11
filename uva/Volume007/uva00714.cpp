#include <bits/stdc++.h>
using namespace std;
const int N=505;
typedef long long LL;
LL m,k,a[N],tag[N];

bool ok(int x){
    int ai=m-1,s;
    for(int i=0;i<k;i++){
        s=0;
        while(ai>=0&&s+a[ai]<=x&&k-i<=ai+1){
            s+=a[ai];
            ai--;
        }
        tag[k-i-1]=ai;
    }
    return ai<0;
}

int main(){
    LL t,L,R,M;
    cin>>t;
    while(t--){
        cin>>m>>k;
        L=R=0;
        for(LL i=0;i<m;i++){
            cin>>a[i];
            L=max(L,a[i]);
            R+=a[i];
        }
        while(L!=R){
            M=(L+R)>>1;
            if(ok(M)){
                R=M;
            }else{
                L=M+1;
            }
        }
        ok(L);
        for(int i=0,j=1;i<m;i++){
            if(i)cout<<' ';
            cout<<a[i];
            if(j<k&&tag[j]==i){
                cout<<" /";
                j++;
            }
        }
        cout<<'\n';
    }
}
