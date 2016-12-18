#include <cstdio>

int main() {
	int h,m,hh,mm,d;
	scanf("%d %d %d %d",&h,&m,&hh,&mm);
	d=hh*60+mm-h*60-m;
	d=(d+1440)%1440; 
	printf("%d %d\n",d/60,d%60);
}
