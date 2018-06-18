#include <bits/stdc++.h>
using namespace std;
bool ok;
int n,a[50];

void dfs(int add,int sum,int ar){
//    cout<<add<<' '<<sum<<' '<<ar<<'\n';
    if(sum>n)return;
    if(sum==n){
        ok=1;
        cout<<1;
        for(int i=1;i<ar;i++){
            if(a[i]==-1){
                cout<<" * 2";
            }else{
                cout<<" + "<<a[i];
            }
        }
        cout<<'\n';
    }
    a[ar]=add+1;
    dfs(add+1,sum+add+1,ar+1);
    a[ar]=-1;
    dfs(add,sum*2,ar+1);
}

int main(){
    a[0]=1;
    while(cin>>n,n){
        ok=0;
        dfs(1,1,1);
        if(!ok){
            cout<<"cheat!\n";
        }
    }
}
