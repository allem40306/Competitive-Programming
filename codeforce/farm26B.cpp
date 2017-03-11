#include <bits/stdc++.h>
using namespace std;
#define N 1000005
unsigned long long ans,n,ni,i,x,y,k,a[N];
int main(){
	for(cin>>n;ni<n;ni++){
		cin>>x>>y;
		a[x]++;
		a[y]--;
	}
	for(i=0;i<N;i++){
		k+=a[i];
		ans+=k*k;
	}
	cout<<ans<<endl;
}
