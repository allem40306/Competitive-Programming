#include <bits/stdc++.h>
using namespace std;
#define N 100
#define K (i+j)%n 
int n,l,i,a[N],b[N];
bool ddd(){
	int i,j,dis;
	for(i=0;i<n;i++){
		dis=a[0]-b[i];
//		cout<<dis<<endl;
		for(j=1;j<n;j++){
//			cout<<j<<' '<<K<<endl;
//			cout<<a[j]<<' '<<b[K]<<endl; 
			if((j<=K&&a[j]==b[K]+dis)||(j>=K&&a[j]==b[K]+dis+l));
			else break;
		}
		if(j==n)return 1;
	}
	return 0;
}
int main(){
	cin>>n>>l;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<n;i++)cin>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	if(ddd())cout<<"YES\n";
	else cout<<"NO\n";
}
