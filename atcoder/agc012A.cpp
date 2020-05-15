#include <bits/stdc++.h>
using namespace std;
#define N 300005
int main(){
	cin.tie(NULL);
	int n,a[N];
	long long ans=0;
	cin>>n;
	for(long long i=0;i<3*n;i++)
		cin>>a[i];
	sort(a,a+3*n);
	for(long long i=1;i<=n;i++)
		ans+=a[3*n-2*i];
	cout<<ans<<'\n';
} 
