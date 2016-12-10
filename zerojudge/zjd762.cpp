#include <cstdio>
#include <cstring>
int a[5]; bool vis[5]; bool b;
 
void di(int c,int d){
	if(c==5){
		//printf("%d %d\n",c,d);
		if(d==23)b=1;
		return;
	}
	for(int i=0;i<5;i++){
		if(!vis[i]){
			vis[i]=1;
			di(c+1,d+a[c]);
			di(c+1,d-a[c]);
			di(c+1,d*a[c]);
			vis[i]=0;
		}
	}
	return;
}

int main(){
	while(scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4])){
		memset(vis,0,sizeof(vis));
		if(!(a[0]||a[1]||a[2]||a[3]||a[4]))break; b=0;
		di(1,a[0]);b?printf("Possible\n"):printf("Impossible\n");		
	}
}
