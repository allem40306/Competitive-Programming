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
unsigned long long int sop(unsigned long long int n){
    unsigned long long int ans=1,mul,add;
    for(int i=0;i<pr;i++){
        if(n%v[i]==0){
            mul=1;
            add=1;
            while(n%v[i]==0){
                mul*=v[i];
                add+=mul;
                n/=v[i];
            }
            ans*=add;
        }
    }
    if(n!=1)ans*=(n+1);
    return ans;
}

int main(){
    unsigned long long int t,n,v;
    cin>>t;
    prime_table();
    while(t--){
        cin>>n;
        v=sop(n);
        if(v<n*2){
            cout<<"deficient\n";
        }else if(v>n*2){
            cout<<"abundant\n";
        }else{
            cout<<"perfect\n";
        }
    }
}
