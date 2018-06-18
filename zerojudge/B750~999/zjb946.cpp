#include <bits/stdc++.h>
using namespace std;

int main(){
    long long s1,s2,t,k,L,R,M;
    while(cin>>s1>>s2>>t>>k){
        L=1; R=k;
        while(L!=R){
            M=(L+R)>>1;
//            cout<<L<<' '<<M<<' '<<R<<'\n';
            if(M*s1+(k-M)*s2>t){
                L=M+1;
            }else{
                R=M;
            }
        }
        if(L*s1+(k-L)*s2==t){
            cout<<L<<' '<<k-L<<'\n';
        }else{
            cout<<"impossible\n";
        }
    }
}
