#include <bits/stdc++.h>
using namespace std;
int main(){
	char a,b;
	cin>>a>>b;
	if(a=='H')cout<<b<<'\n';
	else cout<<char('D'+int('H'-b))<<'\n';
} 
