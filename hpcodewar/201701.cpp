#include <bits/stdc++.h>
using namespace std;
double e=2.718281828,pi=3.141592653,t;
int main(){
	cin.tie(NULL);
	cin>>t;
	printf("%.8f\n",pow(e,-t)*cos(2*pi*t));
}
