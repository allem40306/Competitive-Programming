#include <bits/stdc++.h>
using namespace std;
#define N 10
int n,ni,x,a[N][2];
int ddd(){
	int ans=0;
	for(int i=1;i<=6;i++){
		if((a[i][0]+a[i][1])%2)
			return -1;
		ans+=abs((a[i][0]+a[i][1])/2-a[i][0]);
	}
	return ans/2;
}
int main(){
	cin>>n;
	for(ni=0;ni<n;ni++){
		cin>>x;
		a[x][0]++;
	}
	for(ni=0;ni<n;ni++){
		cin>>x;
		a[x][1]++;
	}
	cout<<ddd()<<endl; 
}
