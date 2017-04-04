#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,c,k,a[N];
int main(){
	cin>>n>>c>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int ans=0,nc,nk=-1;
	for(int i=0;i<n;i++){
		if(nk<a[i]||!nc){
			ans++;
			nc=c-1;
			nk=a[i]+k;
		}else
			nc--;
	}
	cout<<ans<<endl;
}
