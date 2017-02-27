#include <bits/stdc++.h>
using namespace std;
#define N 400000
long long n,k,br,ans;
bool vis[N];
struct lis{
	long long a,b;
}a[N];
struct so{
	long long a,b,c;
}b[2*N];
bool cmp(so a,so b){
	if(a.a!=b.a)
		return a.b>b.b;
	if(a.b!=b.b)
		return a.a>b.a;
	return a.c<b.c;
}
int main(){
	cin>>n>>k;
	for(long long i=0;i<n;i++)
		cin>>a[i].a;
	for(long long i=0;i<n;i++)
		cin>>a[i].b;
	for(long long i=0;i<n;i++){
		if(a[i].a<a[i].b){
			ans+=a[i].a;
			vis[i]=1;
			k--;
		}
		else{
			b[br].a=a[i].a;
			b[br].b=a[i].b;
			b[br++].c=i;
//			printf("%lld %lld %lld\n",b[br-1].a,b[br-1].b,b[br-1].c);
		}
	}
	sort(b,b+br,cmp);
	for(br=0;k>=0;k--){
		if(vis[b[br].c])continue;
//		printf("%lld %lld %lld\n",b[br].a,b[br].b,b[br].c);
		ans+=b[br].a;
		vis[b[br].c]=1;
	}
	for(long long i=0;i<n;i++){
		if(vis[i])continue;
//		printf("%d\n",a[i].b);
		ans+=a[i].b;
	}
	cout<<ans<<endl;
}
