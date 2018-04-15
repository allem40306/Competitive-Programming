#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long a, b, c, d, r;
	while (scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &r) != EOF){
		if (abs(a - c) + abs(b - d)>r)printf("alive\n");
		else printf("die\n");
	}
}