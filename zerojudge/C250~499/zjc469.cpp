#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(cin>>n){
        m=floor(sqrt(n));
        cout<<n-m*m<<'\n';
    }
}
