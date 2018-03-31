#include <bits/stdc++.h>
using namespace std;
const int mod=1000000000+7;
int main(){
    int n,ans,tmp,suf;
    char ch;
    cin>>n;
    getchar();
    while(n--){
        ans=tmp=suf=0;
        while(ch=getchar(),ch!='\n'){
            if(ch=='O'){
                suf++;
                suf%=mod;
                ans+=tmp;
                ans%=mod;
            }else if(ch=='w'){
                tmp+=suf;
                tmp%=mod;
            }

//            cout<<suf<<' '<<tmp<<' '<<ans<<'\n';
        }
        cout<<ans<<'\n';
    }
}
