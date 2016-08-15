#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define N 25
#define M 0.00005

int main(){
	int n, m;
	double arr[N][2];
	while (cin >> n >> m){
		int ma = 10000000, a;
		for (int i = 0; i < m; i++)
			cin >> arr[i][0] >> arr[i][1];
		for (int j = 0; j < m; j++)
			for (int k = j + 1; k < m; k++){
			a = (arr[j][0] - arr[k][0])*(arr[j][0] - arr[k][0]) + (arr[j][1] - arr[k][1])*(arr[j][1] - arr[k][1]);
			if (a < ma)ma = a;
			}
		double ans = sqrt(ma);
		printf("%.4lf\n", ans);
	}
}