#include <iostream>

int main(){
	int ni,n,s,t,s1,t1,r;
	freopen("b915_00.out","w",stdout);
	while(scanf("%d",&n)!=EOF){
		for(ni=0;ni<n;ni++){
			scanf("%d %d %d %d %d",&s,&t,&s1,&t1,&r);
			if(s<s1)
			if(r>=s)printf("<3 she kisses him In the %d sec\n",t1/(s1-s)+(t1%(s1-s)>0)+r);
			else printf("qq she arrives the botom In the %d sec\n",t1/(s1-s)+(t1%(s1-s)>0)+t/s+(t%s>0));
			else printf("qq she arrives the botom In the %d sec\n",(t-t1)/(s-s1)+((t-t1)%(s-s1)>0));
		}
	}
} 
