#include <cstdio>
#include <iomanip>

int main(){
	double f;
	while(scanf("%lf",&f)!=EOF)
		f>0?printf("|%.4f|=%.4f\n",f,f):printf("|%.4f|=%.4f\n",f,-f);
}
