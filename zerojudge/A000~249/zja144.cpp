#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N];

void dfs(int sum,int d,int x){
    if(sum>n)return;
    if(sum==n){
        for(int i=0;i<d;i++){
            if(i)cout<<' ';
            cout<<a[i];
        }
        cout<<'\n';
        return;
    }
    for(int i=x;i>0;i--){
        a[d]=i;
        dfs(sum+i,d+1,i);
    }
    return;
}

int main(){
    while(cin>>n){
        dfs(0,0,n);
    }
}
