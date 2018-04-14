#include <iostream>
#include <algorithm>
#define N 100005
static int a[N],n;
#define R (x+d+n)%n
int dfs(int d,int x,int y,int s){
	printf("%d %d %d %d\n",d,x,y,s);
	if(x==y)return s;
	if(a[x]<a[R])return dfs(d,R,y,s+a[R]-a[x]);
	return dfs(d,R,y,s+n-(a[x]-a[R]));
}

int main(){
	int x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	scanf("%d %d",&x,&y);
	printf("%d\n",std::min(dfs(1,x-1,y-1,0),dfs(-1,x-2,y-1,a[x-1])));
}
