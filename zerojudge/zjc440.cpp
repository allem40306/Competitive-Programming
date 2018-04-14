#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,ans=0,tmp=0,suf=0;
    char ch;
    while(ch=getchar(),ch!='\n'){
        if(ch=='Q'){
            suf++;
            ans+=tmp;
        }else if(ch=='A'){
            tmp+=suf;
        }
    }
    cout<<ans<<'\n';
}
