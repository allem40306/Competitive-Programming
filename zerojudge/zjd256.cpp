#include <cstdio>

int main(){
	int t,ti=0,g,l;
	for(scanf("%d",&t);ti<t;ti++){
		scanf("%d %d",&g,&l);
		g>l||l%g?printf("-1\n"):printf("%d %d\n",g,l);
	}
}
