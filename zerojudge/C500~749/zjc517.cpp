#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    cout<<(a<c||a>e)*min(abs(a-c),abs(a-e))+(b<d||b>f)*min(abs(b-d),abs(b-f))<<'\n';
}
