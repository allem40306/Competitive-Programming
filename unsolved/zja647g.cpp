#include <iostream>
#include <iomanip>
using namespace std;
#define eps 1e-9

int main() {
	int n, i = 0, nn = 1;
	double m, p, x;
	for (cin >> n; i < n; i++){
		cin >> m >> p;
		x = (p / m - 1)*100;
		if(x>-eps)printf("%.2Lf%%", x+eps);
		else printf("%.2Lf%%", x-eps);
		if ((nn==1&&x>=10)||(nn==-1&&x >= 7))printf(" dispose\n");
		else printf(" keep\n");
	}
}
