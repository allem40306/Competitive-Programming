#include <bits/stdc++.h>
using namespace std;
string s;

int dfs(int l,int r){
    int cnt=0;
    for(int i=r-1;i>=l;i--){
        if(s[i]=='(')cnt++;
        else if(s[i]==')')cnt--;
        if(cnt!=0)continue;
        if(s[i]=='+'){
            return dfs(l,i)+dfs(i+1,r);
        }else if(s[i]=='-'){
            return dfs(l,i)-dfs(i+1,r);
        }
    }
    for(int i=r-1;i>=l;i--){
        if(s[i]=='(')cnt++;
        else if(s[i]==')')cnt--;
        if(cnt!=0)continue;
        if(s[i]=='*'){
            return dfs(l,i)*dfs(i+1,r);
        }else if(s[i]=='/'){
            return dfs(l,i)/dfs(i+1,r);
        }else if(s[i]=='%'){
            return dfs(l,i)%dfs(i+1,r);
        }
    }
    if(s[l]=='('&&s[r-1]==')'){
        return dfs(l+1,r-1);
    }
    if(s[l]==' '){
        return dfs(l+1,r);
    }
    if(s[r-1]==' '){
        return dfs(l,r-1);
    }
    int now=0;
    for(int i=l;i<r;i++){
        now=now*10+(s[i]-'0');
    }
    return now;
}

int main(){
    while(getline(cin,s)){
        cout<<dfs(0,s.size())<<'\n';
    }
}
