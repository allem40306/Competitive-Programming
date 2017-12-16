#include <bits/stdc++.h>
using namespace std;
string s,r="";
int rr=0;
bool goal;

int read_target(){
    int x=0;
    bool m=0;
    while(r[rr]!='('&&r[rr]!=')'){
        if(r[rr]=='-'){
            m=1;
            rr++;
            continue;
        }
        x=x*10+(r[rr]-'0');
        rr++;
    }
    return (m?-x:x);
}

int dfs(int g,bool h){
    if(r[rr]==')'){
        return 1;
    }
    int x=read_target(),but=0;//buttom
//    cout<<g<<' '<<x<<'\n';
    for(int i=0;i<1+!h;i++){
        while(1){
            if(r[rr]=='('){
                rr++;
                but+=dfs(h*x+(!h)*(g-x),0);
            }
            if(r[rr]==')'){
                rr++;
                break;
            }
        }
    }
    if(but==2&&g==x)goal=1;
    return 0;
}

int main(){
    int n;
    while(getline(cin,s)){
        stringstream ss(s);
        while(ss>>s){
            r+=s;
        }
    }
    while(rr<r.size()){
        goal=0;
        dfs(0,1);
        if(goal){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }
}
