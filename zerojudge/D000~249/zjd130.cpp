#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define al(x,y) (x+y)*(y-x)/2

int main(){
	double k = 1;
	int tc = 10;
	for (; tc; tc--){
		bool gaa = false; //get an answer
		while (!gaa){
			k++;
			double n = (-1 + sqrt(1 + 8 * k*k)) / 2;
			if (floor(n) == n){
				printf("%10.0lf%10.0lf\n", k, n);
				gaa = true;
			}
		}
	}
}