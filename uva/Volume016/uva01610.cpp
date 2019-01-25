#include <bits/stdc++.h>
using namespace std;
const int N=1005;
string a[N];

string sol(int n){
    string x=a[n/2-1],y=a[n/2];
    string ans="";
    for(int i=0;i<x.size();i++){
        ans+=x[i];
        while(ans[i]<='Z'&&ans<x)++ans[i];
        if(ans[i]<='Z'&&x<=ans&&ans<y)return ans;
        if(x[i]!=ans[i])ans[i]--;
    }
}

int main(){
    int n;
    while(cin>>n,n){
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        cout<<sol(n)<<'\n';
    }
}