#include <bits/stdc++.h>
using namespace std;
#define N 870005
int main(){
	static int a[N]={1},n,ans=0;
	cin>>n;
	for(int i=1;i<n;i++){
		if(a[ans]>1){
//			cout<<1<<'\n';
			a[ans]--;
			ans++;
			a[ans]++;
			a[1]++;
		}else if(ans){
//			cout<<2<<'\n';
			int f=ans;
			while(a[f]<2)f--;
			a[f]--;
			a[f+1]++;
			a[1]++;			
		}else{
//			cout<<3<<'\n';
			a[0]++;
		}
	}
	cout<<ans+1<<'\n';
	cout<<0;
	for(int i=1;i<=ans;i++){
		while(a[i]){
			cout<<' '<<i;
			a[i]--;
		}
	}
	cout<<'\n';
}
