#include <bits/stdc++.h>
using namespace std;

int main(){
    double s,r1,r2,r3,r4,a,b,c;
    while(cin>>s){
        r1=s*sqrt(3)/2;
        r2=s/(1+sqrt(12)/3);
        r3=r1/2;
        a=5.0/3.0;
        b=(sqrt(3)*7.0/3)*s;;
        c=-(s*s*(7.0/4));
        r4=(-b+sqrt(b*b-4*a*c))/a/2;
        cout<<fixed<<setprecision(10)<<r1<<' '<<r2<<' '<<r3<<' '<<r4<<'\n';
    }
}
