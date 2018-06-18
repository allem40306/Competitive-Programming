#include <cstdio>
#define N 100005

int main(){
	int n,a[N],ti=0,t;
	for(scanf("%d",&t);ti<t;ti++){
		int a1=-10000,a2=0,ar=0; a[0]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>0)a2+=a[i];
			a[i]+=a[i-1];
		}
		for(int i=1;i<=n;i++){
			if(a[i]-a[ar]>a1)a1=a[i]-a[ar];
			if(a[i]<a[ar])ar=i;
		}
		if(!a2)a2=a1;
		printf("%d %d\n",a1,a2);
	}
}
