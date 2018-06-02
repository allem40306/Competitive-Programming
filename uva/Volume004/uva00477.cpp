#include <bits/stdc++.h>
using namespace std;

int main(){
	char c[20];
	float f[20][4];
	int fr = 0,cr=1;
	while (cin >> c[fr], c[fr] != '*'){
		if(c[fr]=='r')cin >> f[fr][0] >> f[fr][1] >> f[fr][2] >> f[fr][3];
		else cin >> f[fr][0] >> f[fr][1] >> f[fr][2];
		fr++;
	}
	float a, b;
	while (cin >> a >> b, a < 9999.9){
		bool isin = false;
		for (int i = 0; i < fr; i++){
			if ((c[i]=='r' && a > f[i][0] && a < f[i][2] && b > f[i][3] && b < f[i][1])||(c[i]=='c'&&(a-f[i][0])*(a-f[i][0])+(b-f[i][1])*(b-f[i][1])<=f[i][2]*f[i][2])){
                printf("Point %d is contained in figure %d\n", cr, i + 1), isin = true;
			}
		}
		if (!isin)
			printf("Point %d is not contained in any figure\n", cr);
		cr++;
	}
}
