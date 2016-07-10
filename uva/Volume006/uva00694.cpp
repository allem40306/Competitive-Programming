#include <iostream>
using namespace std;
#define N 105
#define MIN(x,y) x<y?x:y

int main(){
	long long a, n;
	int m, ca = 1;
	while (cin >> a >> m, a >= 0){
		n = a;
		int te = 1;
		while (n != 1&&n<=m){
			if (n % 2)n = 3 * n + 1;
			else n = n / 2;
			te++;
		}
		if (n > m)te--;
		printf("Case %d: A = %lld, limit = %d, number of terms = %d\n", ca++, a, m, te);
	}
}