#include <bits/stdc++.h>
using namespace std;
int p[20]={2,3,5,7,11,13,17,19,23,29,31};
bool b[20],used[20];
int n,ans[20];

void sol(int s){
    if(n==s){
        for(int i=0;i<n;i++){
            if(i)cout<<' ';
            cout<<ans[i];
        }
        cout<<'\n';
        return;
    }
    for(int i=2;i<=n;i++){
        if(!used[i]&&(b[ans[(s-1+n)%n]+i])&&(s!=n-1||b[ans[0]+i])){
            ans[s]=i;
            used[i]=1;
            sol(s+1);
            used[i]=0;
        }
    }
    return;
}

int main(){
    memset(b,0,sizeof(b));
    for(int i=0;i<11;i++)b[p[i]]=1;
    int tc=0;
    ans[0]=1;
    while(cin>>n){
        memset(used,0,sizeof(used));
        used[1]=1;
        if(tc++)cout<<"\n";
        cout<<"Case "<<tc<<":\n";
        sol(1);
    }
}
