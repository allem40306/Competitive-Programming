#include <bits/stdc++.h>
using namespace std;
int main(){
	double a,t1,t2,b,t3;
	char ch;
	while(cin>>a>>ch>>t1>>ch>>t2>>ch>>b>>ch>>t3){
		printf("%.1lf\n",a*t1*t1/2.0+t2*a*t1+a*t1*t3-b*t3*t3/2.0);
	}
}
