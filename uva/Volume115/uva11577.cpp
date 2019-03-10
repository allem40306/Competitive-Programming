#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,f[26];
    string s;
    cin>>t>>ws;
    while(t--){
        getline(cin,s);
        memset(f,0,sizeof(f));
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])){
                f[tolower(s[i])-'a']++;
            }
        }
        int mx=*max_element(f,f+26);
        for(int i=0;i<26;i++){
            if(mx==f[i]){
                cout<<char('a'+i);
            }
        }
        cout<<'\n';
    }
}
