#include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned long long a,b,k;
	cin>>k>>a>>b;
	if(k>a&&k>b)cout<<"-1\n";
	else cout<<a/k+b/k<<endl;
}
