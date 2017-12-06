#include <bits/stdc++.h>
using namespace std;

int f(int n){
    int ans=0;
    while(n){
        ans+=n%10;
        n/=10;
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n;
    if(n%f(n)==0){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}
