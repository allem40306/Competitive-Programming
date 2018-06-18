#include  <bits/stdc++.h>
using namespace std;

int main(){
    double a,b,c;
    while(cin>>a>>b>>c){
        cout<<fixed<<setprecision(2)<<sqrt(c*c-b*b+a*a)<<'\n';
    }
}
