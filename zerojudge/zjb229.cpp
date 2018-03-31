#include <bits/stdc++.h>
using namespace std;
const int N=55;
unsigned long long int U[N]={0,1},L[N]={0,1},R[N]={0,1};

int main(){
    for(int i=2;i<N;i++){
        U[i]=L[i-1]+R[i-1]+U[i-1];
        L[i]=L[i-1]+U[i-1];
        R[i]=R[i-1]+U[i-1];
    }
    int n;
    while(cin>>n){
        cout<<U[n]+L[n]+R[n]<<'\n';
    }
}
