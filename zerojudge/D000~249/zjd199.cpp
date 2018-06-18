#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a,b,c;
    while(cin>>a>>b>>c){
        cout<<fixed<<setprecision(0)<<sqrt((a+b+c)*(a+b+c)-4*a*c)<<'\n';
    }
}
