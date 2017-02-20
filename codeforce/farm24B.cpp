#include <bits/stdc++.h>
using namespace std;
#define N 1000000
long long a,b,c,d,x,i,j,k,m,ans[N];
int main(){
	cin>>a>>b;
	for(i=1;;i++){
		c=(a/i)+1*(a%i>0);
		d=(b/i);
		x=d-c+1;
		if(x<3)break;
		ans[i]=x*(x-1)*(x-2)/6;
		}
	for(k=i;i;i--){
		for(j=k;j>i;j--){
			if(j%i==0)
				ans[i]-=ans[j];
		}
	}
	for(i=1;i<=k;i++){
		if(ans[i]>0)
			cout<<i<<' '<<ans[i]<<endl;
	}
}
