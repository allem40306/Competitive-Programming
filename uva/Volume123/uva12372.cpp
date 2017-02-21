#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,t,ti=1;
	for(cin>>t;ti<=t;ti++){
		cin>>a>>b>>c;
		cout<<"Case "<<ti<<": ";
		if(a>20||b>20||c>20)
			cout<<"bad\n";
		else
			cout<<"good\n";
	}
}
