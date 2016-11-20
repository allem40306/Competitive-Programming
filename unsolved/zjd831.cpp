#include <iostream>
#define N 2000000
static int djs[N][2];

void init(){
	for(int i=0;i<N;i++){
		djs[i][0]=i;
		djs[i][1]=1;
	}
}

int f(int x){
	return x==djs[x][0]?x:x=f(djs[x][0]);
}

int Union(int x,int y){
	int fx=f(x),fy=f(y);
	if(fx==fy)return 1;
	djs[fx][1]+=djs[fy][1];
	djs[fy][0]=djs[fx][0];
	return djs[fx][1];
}

int main(){
	int n,m,x,y;
	while(scanf("%d %d",&n,&m)!=EOF){
		init(); 
		int ans=1;
		for(int mi=0;mi<m;mi++){
			scanf("%d %d",&x,&y);
			int a=Union(x,y);
			ans=(ans>a?ans:a);
		}
		printf("%d\n",ans);
	}
}
