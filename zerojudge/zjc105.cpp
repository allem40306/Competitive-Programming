#include <bits/stdc++.h>
using namespace std;
const int N=1000;
int main(){
    int t,ai,ans,tans;
    double x[N],y[N],z;
    bool b=0;
    map<double,int>tb;
    string s;
    cin>>t>>ws;
    for(int ti=0;ti<t;ti++){
        ans=ai=0;
        while(getline(cin,s)){
            if(s=="")break;
            stringstream ss(s);
            ss>>x[ai]; ss>>y[ai];
//            cout<<x[ai]<<' '<<y[ai]<<'\n';
            ai++;
        }
        for(int i=0;i<ai;i++){
            tb.clear();
//            cout<<i<<'\n';
            tans=0;
            for(int j=0;j<ai;j++){
                if(i==j)continue;
//                cout<<double(x[j]-x[i])/(y[j]-y[i])<<'\n';
                tb[double(x[j]-x[i])/(y[j]-y[i])]++;
                tans=max(tans,tb[double(x[j]-x[i])/(y[j]-y[i])]);
            }
            if(tans>ans)ans=tans;
        }
        if(b)cout<<'\n';
        b=1;
        cout<<ans+1<<'\n';
    }
}
