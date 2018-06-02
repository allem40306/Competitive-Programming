#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    while(getline(cin,s)){
        if(s[0]!='|')continue;
        int v=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')v=v<<1;
            else if(s[i]=='o')v=(v<<1)+1;
        }
        cout<<char(v);
    }
    cout<<'\n';
}
