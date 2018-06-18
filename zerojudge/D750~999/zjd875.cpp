#include <bits/stdc++.h>
using namespace std;
const int N=100000;
int main(){
    int l,ans[N],n;
    bool o;
    while(cin>>l){
        memset(ans,0,sizeof(ans));
        n=1;
        o=0;
        while(l){
            if(l>=2*n){
                ans[n]+=2;
                l-=2*n;
            }else{
                ans[min(l,n)]++;
                l-=min(l,n);
            }
            n++;
        }
        for(int i=1;i<n;i++){
            while(ans[i]>1){
                if(o)cout<<' ';
                o=1;
                cout<<i;
                ans[i]--;
            }
        }
        for(int i=n-1;i>0;i--){
            while(ans[i]){
                if(o)cout<<' ';
                o=1;
                cout<<i;
                ans[i]--;
            }
        }
        cout<<'\n';
    }
}
