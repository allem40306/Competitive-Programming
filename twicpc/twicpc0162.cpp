#include <bits/stdc++.h>
using namespace std;
const int N=20;
int n,v,a[N],nans,lim;
queue<string>q;

string s;
string its(int x){
    if(!x)return "0";
    s="";
    while(x){
        s=char(x%10+'0')+s;
        x/=10;
    }
    return s;
}

void sol(int x,int val,string s){
//    cout<<s<<'\n';
    if(x==n){
        if(val==v){
            nans++;
            q.push(s);
        }
        return;
    }
    if(x)s+='^';
    for(int i=0;i<=lim;i++){
        if(i<=a[x]){
            sol(x+1,val^i,s+its(i));
        }
    }
}

int main(){
    cin>>n>>v;
    lim=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        lim=max(lim,a[i]);
    }
    nans=0;
    sol(0,0,"");
    cout<<nans<<'\n';
    while(!q.empty()){
        cout<<q.front()<<'='<<v<<'\n';
        q.pop();
    }
}
