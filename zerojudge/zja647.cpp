#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n, i = 0, nn = 1;
	double m, p, x;
	for (cin >> n; i < n; i++){
		cin >> m >> p;
		x = p / m - 1;
		x *= 10000;
		if (x < 0){ nn = -1; x *= -1; }
		else nn = 1;
		if (nn == -1)
			printf(x>1000?"-":" -");
		else
			printf(x>1000?" ":"  ");
		x/=100;
		printf("%.2lf", x+1e-9);
		cout << '%';
		if ((nn==1&&x>=10)||(nn==-1&&x >= 7))printf(" dispose\n");
		else printf(" keep\n");
	}
}
