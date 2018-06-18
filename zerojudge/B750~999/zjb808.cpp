#include <bits/stdc++.h>
using namespace std;
const int N=1000000;
int v[600000],pr=0;
bitset<N>b;
void prime_table(){
    b.reset();
    for(int i=2;i<N;i++){
        if(!b[i]){
            v[pr++]=i;
        }
        for(int j=0;j<pr&&i*v[j]<N;j++){
            b[i*v[j]]=1;
        }
    }
}

long long sol(long long n){
    int ans=1,mul;
    for(int i=0;i<pr;i++){
        if(n%v[i]==0){
            mul=1;
            while(n%v[i]==0){
                mul++;
                n/=v[i];
            }
            ans*=mul;
        }
    }
    if(n!=1)ans*=2;
    return ans;
}

int main(){
    long long  c;
    prime_table();
    while(cin>>c,c){
        cout<<c<<' '<<sol(4*c-3)<<'\n';
    }
}
