#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL que(LL a,LL b){
    if(a>b){
        if(a%b){
            return (1+que(b,a%b))<<(a/b);
        }
        return 1LL<<(a/b-1);
    }if(a<b){
        return 1+que(b,a);
    }
    return 1;
}

int main(){
    int a,b;
    while(cin>>a>>b){
        cout<<que(a,b)<<'\n';
    }
}
