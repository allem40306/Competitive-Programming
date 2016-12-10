#include <iostream>
#include <iomanip>

int main(){
	float f;
	while(scanf("%f",&f)!=EOF)
		f>0?printf("|%.4f|=%.4f\n",f,f):printf("|%.4f|=%.4f\n",f,-f);
}
