#include <cstdio>

int main() {
	double a,b,c,d;int t,ti=0;
	for(scanf("%d",&t);ti<t&&(scanf("%lf %lf %lf %lf",&a,&b,&c,&d));ti++,printf(b||d?("No\n"):(a==c?"=\n":(a>c?">\n":"<\n"))));
}
