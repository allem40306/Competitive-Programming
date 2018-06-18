#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	char c;
	float f[20][4];
	int fr = 0, cr = 1;
	while (cin >> c, c != '*'){
		cin >> f[fr][0] >> f[fr][1] >> f[fr][2] >> f[fr][3];
		fr++;
	}
	float a, b;
	while (cin >> a >> b, a < 9999.9){
		bool isin = false;
		for (int i = 0; i < fr; i++){
			if (a > f[i][0] && a < f[i][2] && b > f[i][3] && b < f[i][1])
				printf("Point %d is contained in figure %d\n", cr, i + 1), isin = true;
		}
		if (!isin)
			printf("Point %d is not contained in any figure\n", cr);
		cr++;
	}
}