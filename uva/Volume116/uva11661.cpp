#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,ans,R,D;
    string s;
    while(cin>>n,n){
        ans=R=D=400000;
        cin>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='.')continue;
            if(s[i]=='Z'){
                ans=0;
                break;
            }
            if(s[i]=='R'){
                R=i;
            }else{
                D=i;
            }
            ans=min(ans,abs(R-D));
        }
        cout<<ans<<'\n';
    }
}
