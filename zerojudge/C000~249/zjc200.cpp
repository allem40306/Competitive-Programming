#include <bits/stdc++.h>
using namespace std;
#define dth(x) int(x<='Z'&&x>='A'?x-'A'+10:x-'0')
int main(){
    int ans,n;
    string s;
    cin>>n;
    while(n--){
        cin>>s;
        ans=0;
        for(int i=0;i<s.size();i++){
            ans=(ans*36+dth(s[i]))%1688;
        }
        cout<<ans%1688+1<<'\n';
    }
}
