#include <iostream>
#include <iomanip>
using namespace std;
#define cf(a) a*5/9
int main() {
	int t,i=1;
	float c,d;
	for(scanf("%d",&t);i<=t;i++){
		scanf("%f %f",&c,&d);
		printf("Case %d: %2.3f\n",i,cf(d)+c);
	}
}
