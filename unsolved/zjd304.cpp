#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL mi,wa,n;
vector<string>ans;

void dfs(string s,LL tot,LL cop,LL step){
    if(tot>n||step>mi)return;
    if(tot==n){
        if(step<mi){
            ans.clear();
            wa=1;
            mi=step;
            ans.push_back(s);
            return;
        }
        if(step==mi){
            wa++;
            ans.push_back(s);
            return;
        }
        return;
    }
    if(tot!=cop){
        dfs(s+" + C",tot,tot,step+1);
    }
    dfs(s+" + V",tot+cop,cop,step+1);
}

int main(){
    while(cin>>n){
        ans.clear();
        mi=10000;
        wa=0;
        dfs("Ctrl C",1,1,1);
        cout<<"min : "<<mi<<'\n';
        cout<<"way : "<<wa<<'\n';
        for(int i=0;i<wa;i++){
            cout<<ans[i]<<'\n';
        }
    }
}
