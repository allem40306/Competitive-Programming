#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define N 1000

int main(){
	int n, m;
	double f, c; //first cost
	double d[N];
	while (cin >> n >> f >> c >> m,n >= 0){
		for (int i = 0; i < N; i++)d[i] = 0.0;
		int dr = 0;
		while (m--){
			cin >> dr;
			cin >> d[dr];
		}
		double v = f + c, o = c, e = c / n; //vaule owes earn
		for (int i = 0; i <= n; i++){
			d[i] = (d[i]>0 ? d[i] : d[i - 1]);
			v *= 1 - d[i];
			if (v >= o){
				printf("%d month%s\n", i,i != 1 ? "s" : "");
				break;
			}
			o -= e;
		}
	}
}