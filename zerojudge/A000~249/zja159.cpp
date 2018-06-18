#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,v;
    string s;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int ti=1;ti<=n;ti++){
        v=0;
        for(int i=0;i<4;i++){
            cin>>s;
            v+=int(s[1]-'0')+int(s[3]-'0')+(int(s[0]-'0')*2)/10+(int(s[0]-'0')*2)%10+(int(s[2]-'0')*2)/10+(int(s[2]-'0')*2)%10;
//            cout<<v<<'\n';
        }
        if(v%10){
            cout<<"Invalid\n";
        }else{
            cout<<"Valid\n";
        }
    }
}
//1539918105190199
