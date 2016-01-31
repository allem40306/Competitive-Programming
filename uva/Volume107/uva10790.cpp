#include <iostream>
#include <cmath>
using namespace std;
#define x(a) a*(a-1)/2
int main() {
	long long a,b;
	int t=1;
	while(scanf("%d %d",&a,&b)!=EOF){
		if(!(a||b))break;
	    printf("Case %d: %lld\n", t++, (long long)x(a)*x(b));
    }
}
