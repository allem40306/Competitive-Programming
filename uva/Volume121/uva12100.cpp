#include <bits/stdc++.h>
using namespace std;
const int N=105;
int main(){
    int t,n,m;
    int a[N],b[N],order[N];// order 第幾個被執行
    cin>>t;
    while(t--){
        int tot=0;
        queue<int>q;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>a[i];
            b[i]=a[i];
            q.push(i);
        }
        sort(b,b+n,greater<int>());
        while(tot!=n){
            int k=q.front(); q.pop();
            if(a[k]!=b[tot]){
                q.push(k);
            }else{
                order[k]=++tot;
            }
        }
        cout<<order[m]<<'\n';
    }
}