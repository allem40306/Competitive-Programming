#include <bits/stdc++.h>
using namespace std;
#define N 100005
long long n,m,a[N],b[N],ti=1;
bool pk(int i,int aa,int nn,int bb,int mm){
//	printf("*%d %d %d %d %d\n",i,aa,nn,bb,mm);
	if(nn<0)return !i;
	if(aa>bb)return i;
	if(i){
//		printf("%d %d %d %d %d\n",i,aa+a[nn],nn,bb,mm);
		if(aa+a[nn]>=bb)return pk(!i,bb,mm,aa+a[nn],nn-1);
	
	}
	else{
//		printf("%d %d %d %d %d\n",i,aa+b[nn],nn,bb,mm);
		if(aa+b[nn]>=bb)return pk(!i,bb,mm,aa+b[nn],nn-1);		
	}
	return !i;
}

int main(){
	while(cin>>n>>m){
		for(int i=0;i<n;i++)cin>>a[i];
		for(int j=0;j<m;j++)cin>>b[j];
		cout<<"Case "<<ti++<<": ";
		sort(a,a+n);
		sort(b,b+m);
		if(pk(1,a[n-1],n-2,b[m-1],m-2))
			cout<<"Takeover Incorporated\n";
		else
			cout<<"Buyout Limited\n";
	}
}
