#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,ni=0,a[N];

bool solve(){
	for(int i=0;i<n-2;i++){
		if(a[i]+a[i+1]>a[i+2])
			return 1;
	}
	return 0;
}

int main(){
	for(cin>>n;ni<n;ni++)
	cin>>a[ni];
	sort(a,a+n);
	if(solve())cout<<"YES\n";
	else cout<<"NO\n";
}
