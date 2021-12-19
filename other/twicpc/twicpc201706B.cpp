#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin.tie(NULL);
	long long n,k,a[100005];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		k-=a[i];
	}
	sort(a,a+n,cmp);
	long long ans=0; 
	for(int i=0;i<n;i++){
		ans+=(i+1)*a[i];
	}
	cout<<ans+k*n<<'\n';
}
