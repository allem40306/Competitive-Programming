#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,r="qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    while(getline(cin,s)){
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')continue;
            s[i]=tolower(s[i]);
            s[i]=r[find(r.begin(),r.end(),s[i])-r.begin()-2];
        }
        cout<<s<<'\n';
    }
}
