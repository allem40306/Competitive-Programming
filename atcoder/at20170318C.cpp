#include <bits/stdc++.h>
using namespace std;
int main(){
	double x;
	int y;
	cin>>x;
	y=(-1+sqrt(1+4*x))/2;
	for(;y*(y+1)/2<x;y++);
	cout<<y<<'\n';
}
