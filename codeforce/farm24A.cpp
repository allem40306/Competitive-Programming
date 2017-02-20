#include <bits/stdc++.h>
using namespace std;
#define N 100
int main(){
	long long n,a[N],ans=0;
	cin>>n;
	for(int i=0;i<2*n;i++)cin>>a[i];
	sort(a,a+2*n);
	for(int i=0;i<n;i++)
		ans+=a[2*i+1]-a[2*i];
	cout<<ans<<endl;
}
