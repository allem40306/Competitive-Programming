#include <iostream>
using namespace std;
#define N 1000005

int main(){
	static int n,a[N],i,j,j1,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	a[0]=a[n+1]=0;
	for(i=1;i<=n;i++){
		for(j=i-1,j1=i+1;j>=0;j--,j1++){
			if(a[j]<a[i]&&(ans+=i-j))break;
			if(a[j1]<a[i]&&(ans+=j1-i))break;
		}
	}
	printf("%d\n",ans);
}
