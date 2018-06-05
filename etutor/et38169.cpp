#include <iostream>
#include <math.h>
using namespace std;
const double PI=acos(-1.0);

int main(){
	double a,b;
	scanf("%lf%lf",&a,&b);
	printf("%.3lf\n",a*b*M_PI);
}
