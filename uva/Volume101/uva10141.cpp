#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,r,co,ans_r,ti=1;
    double p,ans_p;
    string ans,s,t;
    while(cin>>n>>m,n||m){
        cin>>ws;
        for(int i=0;i<n;i++){
            getline(cin,t);
        }
        ans_r=ans_p=0;
        for(int i=0;i<m;i++){
            getline(cin,s);
            cin>>p>>r>>ws;
            co=0;
            for(int j=0;j<r;j++){
                getline(cin,t);
            }
            if(r>ans_r||(r==ans_r&&p<ans_p)){
                ans=s;
                ans_r=r;
                ans_p=p;
            }
//            cout<<ans<<' '<<ans_co<<' '<<ans_p<<'\n';
        }
        if(ti>1)cout<<'\n';
        cout<<"RFP #"<<ti++<<'\n';
        cout<<ans<<'\n';
    }
}
