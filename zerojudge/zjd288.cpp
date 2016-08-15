#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define N 1005

template<typename T>
T det(T a, T b, T c, T d){
	if(a*d>b*c)return a*d - b*c;
	return b*c - a*d;
}

int main(){
	int n;
	double f[N][2], ans;
	while (cin >> n){
		ans = 0.0;
		for (int i = 0; i < n; i++)
			cin >> f[i][0] >> f[i][1];
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				for (int k = j + 1; k < n; k++){
			double ans2 = det(f[i][0] - f[j][0], f[i][1] - f[j][1], f[i][0] - f[k][0], f[i][1] - f[k][1]);
			if (ans2 > ans)ans = ans2;
				}
		printf("%.6f", ans/2);
	}
}