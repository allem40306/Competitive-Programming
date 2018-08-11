#include <bits/stdc++.h>
using namespace std ;

int main(){
	double s,a;
	string t;
	while(cin>>s>>a>>t){
		double arc,chord;
		s+=6440;
		if(a>180)a=360-a;
		if(t=="min")a/=60;
		arc=2*acos(-1.0)*s*a/360;
		chord=sqrt(2*s*s-2*s*s*cos(a*acos(-1.0)/180));
		cout<<fixed<<setprecision(6)<<arc<<' '<<chord<<'\n';
	}
}