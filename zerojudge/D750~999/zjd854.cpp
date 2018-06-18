#include <iostream>
double a, b, c, d;
double D(double x) { return a*x*x*x + b*x*x + c*x + d; }

int main(){
	while (scanf("%lf %lf %lf %lf", &a, &b, &c, &d) == 4){
		for (int i = -100000; i <= 100000; i++){
			  double f1 = D(i/1000.0), f2 = D((i-1)/1000.0);
			  if (f1*f2<=0)
				printf("%.2lf ", i / 1000.0), i += 1000;
		}
		printf("\n");
		
	}
}
