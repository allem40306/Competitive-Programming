#include <iostream>
#include <iomanip>

int main(){
	double f;
	while(scanf("%lf",&f)!=EOF)
		f>0?printf("|%.4lf|=%.4lf\n",f,f):printf("|%.4lf|=%.4lf\n",f,-f);
}
