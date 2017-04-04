#include <bits/stdc++.h>
using namespace std;
#define N 5005
int main(){
	cin.tie(NULL);
	int n,k,ans=-1,sum,a[N];
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,greater<int>());
	for(int i=0;i<n;i++){
		sum=0;
		for(int j=i;j<n;j++){
			if(sum+a[j]<k){
				sum+=a[j];
				continue;
			}
			ans=max(ans,j);
		}
	}
	cout<<n-ans-1<<'\n'; 
} 
