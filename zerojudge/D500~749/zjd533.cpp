#include <cstdio>

int main() {
	double a,b,c,d;int t,ti=0;
	for(scanf("%d",&t);ti<t;ti++){
		scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
		if (b||d)printf("No\n");
		else if(a==c)printf("=\n");
		else if(a>c)printf(">\n");
		else printf("<\n");
	}
}
