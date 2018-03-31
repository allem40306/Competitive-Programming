#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int main(){
    int n,m,x,a[N],ans=N,c,p;
    queue<pair<int,int>>q;
    while(cin>>n>>m){
        while(!q.empty())q.pop();
        memset(a,0,sizeof(a));
        ans=c=0;
        for(int i=0;i<m;i++){
            cin>>x;
            a[x]++;
        }
        p=n/m;
        for(int i=1;i<n;i++){
            while(a[i]<p&&!q.empty()){
                ans=max(ans,n-q.front().first);
                a[i]+=min(q.front().second,p-a[i]);
                q.front().second-=min(q.front().second,p-a[i]);
            }
        }
    }
}
