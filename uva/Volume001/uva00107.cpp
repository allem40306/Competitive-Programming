#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define eps 1e-8
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    LL h,w,n,t;
    while(cin>>h>>w,h||w){
        if(h==1&&w==1){
            cout<<"0 1\n";
            continue;
        }
        t=1;
        while(h!=(long long)(pow(pow(w,1.0/t)+1.0,t)+eps))t++;
        n=(long long)(pow(w,1.0/t)+eps);
        if(n==1){
            cout<<t<<' '<<(h-w)*(n+1)+w<<'\n';
        }else{
            cout<<(1-w)/(1-n)<<' '<<(h-w)*(n+1)+w<<'\n';
        }
    }
}
