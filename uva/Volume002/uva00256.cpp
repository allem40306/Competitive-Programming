#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v[5];
    int big=100,mod=10;
    for(int i=1;i<=4;i++){
        for(int j=0;j<big;j++){
            if((j/mod+j%mod)*(j/mod+j%mod)==j){
                v[i].push_back(j);
            }
        }
        big*=100;
        mod*=10;
    }
    int n;
    while(cin>>n){
        for(auto it:v[n/2]){
            cout<<setfill('0')<<setw(n)<<it<<'\n';
        }
    }
}
