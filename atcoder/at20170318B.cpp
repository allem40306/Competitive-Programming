#include <bits/stdc++.h>
using namespace std;
int main(){
	int w,a,b;
	cin>>w>>a>>b;
	if(abs(b-a)<w)cout<<0<<'\n';
	else cout<<(a<b?b-a-w:a-b-w)<<'\n';
} 
