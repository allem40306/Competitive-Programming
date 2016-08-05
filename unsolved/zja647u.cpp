#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n, i = 0, nn = 1;
	double m, p, x;
	for (cin >> n; i < n; i++){
		cin >> m >> p;
		x = p / m - 1;
		x *= 100;
		if (x < 0){ nn = -1; x *= -1; }
		else nn = 1;
		if (nn == -1){
			if (x>10)printf("-");
			else printf(" -");
		}
		else{
			if (x<10)printf("  ");
			else printf(" ");
		}
		printf("%.2f", x);
		cout << '%';
		if ((nn == 1 && x >= 10) || (nn == -1 && x >= 7))printf(" dispose\n");
		else printf(" keep\n");
	}
}