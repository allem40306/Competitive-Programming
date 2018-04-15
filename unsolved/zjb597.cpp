#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000
int n,ni,ar[N],j,sum,mx;
bool vis[N];
bool dfs(int t,int a,int m,int n){ //target accumulate
	if(!m)return 1;
	if(t==a)a=0;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			if(a+ar[i]>t)return 0;
			vis[i]=1;
			if(dfs(t,a+ar[i],m-1,n))return 1;
			vis[i]=0;
		}
	}
	return 0;
}
bool dfs1(int t,int a,int m,int n){
	memset(vis,0,sizeof(vis));
	return dfs(j,0,n,n);
}
int main(){
	while(scanf("%d",&n),n){
		sum=mx=0;
		for(ni=0;ni<n;ni++){
			scanf("%d",&ar[ni]);
			sum+=ar[ni];
			if(mx<ar[ni])mx=ar[ni];
		}
		std::sort(ar,ar+n);
		for(j=mx;j*2<=sum;j++){
			if(j==sum||(sum%j==0&&dfs1(j,0,n,n))){
				printf("%d\n",j);
				break;
			}
		} 
	}
}
