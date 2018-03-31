#include <bits/stdc++.h>
using namespace std;
const int END=4294967295;
int main(){
    int n,a[3][12],b[3][12];
    string s,t,r[3];
    bool flag,used;
    cin>>n;
    for(int ti=0;ti<n;ti++){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<3;i++){
            cin>>s>>t>>r[i];
            for(int j=0;j<s.size();j++){
                a[i][s[j]-'A']=1;
                b[i][t[j]-'A']=1;
            }
        }
        for(int i=0;i<12;i++){
            flag=1; used=0;
            for(int j=0;j<3;j++)
                if(a[j][i]||b[j][i])used=1;
            if(!used)continue;
            for(int j=0;j<3;j++){
                if(a[j][i]&&r[j]!="down")flag=0;
                if(b[j][i]&&r[j]!="up")flag=0;
            }
            if(flag){
                if(ti)cout<<'\n';
                cout<<char('A'+i)<<" is the counterfeit coin and it is light.\n";
                break;
            }
            flag=1;
            for(int j=0;j<3;j++){
                if(a[j][i]&&r[j]!="up")flag=0;
                if(b[j][i]&&r[j]!="down")flag=0;
            }
            if(flag){
                if(ti)cout<<'\n';
                cout<<char('A'+i)<<" is the counterfeit coin and it is heavy .\n";
                break;
            }
        }
    }
}
