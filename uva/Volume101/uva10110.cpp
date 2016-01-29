#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	unsigned int n,x;
	while ( scanf("%u",&n)){
		if(n==0)break;
		x=sqrt(n);
		printf(n==x*x?"yes\n":"no\n");
	}
}
