#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k,x,y,z;
    cin>>n>>k;
    x=(2*((k-1)/n)+n)%n;
    y=(n/2-(k-1)/n+n)%n;
    z=(k%n-1+n)%n;
    cout<<(x-z+n)%n+1<<' '<<(y+z)%n+1<<'\n';
}
