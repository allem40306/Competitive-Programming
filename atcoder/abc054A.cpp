#include <bits/stdc++.h>
using namespace std;
#define t(x) x==1?14:x
int main(){
	int a,b;
	cin>>a>>b;
	a=t(a);b=t(b);
	if(a>b)cout<<"Alice\n";
	else if(a<b)cout<<"Bob\n";
	else cout<<"Draw\n";
}
