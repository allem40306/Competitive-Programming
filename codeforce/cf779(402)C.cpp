#include <bits/stdc++.h>
using namespace std;
#define N 400000
long long n,ii,k,br,ans;
bool vis[N];
struct List{
	long long a,b;
}a[N];
bool cmp(List a,List b){
	return a.a-a.b<b.a-b.b;
}
int main(){
	cin>>n>>k;
	for(long long i=0;i<n;i++)
		cin>>a[i].a;
	for(long long i=0;i<n;i++)
		cin>>a[i].b;
	sort(a,a+n,cmp);
	for(ii=0;ii<k;ii++){
		ans+=a[ii].a;
	}
	for(ii=k;ii<n;ii++){
		ans+=min(a[ii].a,a[ii].b);
	}
	cout<<ans<<endl;
}
