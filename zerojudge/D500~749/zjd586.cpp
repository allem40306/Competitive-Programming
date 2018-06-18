#include <bits/stdc++.h>
using namespace std;
string s="uzrmatifxopnhwvbslekycqjgd",s2="mjqhofawcpnsexdkvgtzblryui",r;
int sti(string s){
    if(s.size()%2){
        return s[0]-'0';
    }else{
        return 10*(s[0]-'0')+(s[1]-'0');
    }
}
int main(){
    int t,n,ans,x;
    size_t sz;
    char ch;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>r;
        if(isalpha(r[0])){
            sz=s.find(r[0]);
            ans=int(sz)+1;
            for(int i=1;i<n;i++){
                cin>>ch;
                sz=s.find(ch);
                ans+=int(sz)+1;
            }
            cout<<ans<<'\n';
        }else{
            cout<<s2[sti(r)-1];
            for(int i=1;i<n;i++){
                cin>>x;
                cout<<s2[x-1];
            }
            cout<<'\n';
        }
    }
}
