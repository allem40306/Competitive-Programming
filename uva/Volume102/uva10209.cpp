#include <bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);

int main(){
    double a,x,y,z;
    while(cin>>a){
        z=a*a*(1-sqrt(3.0)/4.0-PI/6.0);
        y=a*a*(1-PI/4.0)-2*z;
        x=a*a-4*y-4*z;
        cout<<fixed<<setprecision(3)<<x<<' '<<4*y<<' '<<4*z<<'\n';
    }
}
