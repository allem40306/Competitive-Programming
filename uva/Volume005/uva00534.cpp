#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(){
	int i, j, k, n, m[200][200], x[200], y[200],ca=1;
	while (cin >> n, n){
		cout << fixed<< setprecision(3) ;
		for (i = 0; i < n; i++){
			cin >> x[i] >> y[i];
			for (j = 0; j < i; j++)
				m[i][j] = m[j][i] = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
		}
		for (k = 0; k < n; k++)
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					m[i][j] = m[j][i] = min(m[i][j], max(m[i][k], m[k][j]));
		cout << "Scenario #" << ca++ << "\nFrog Distance = " <<sqrt(double(m[0][1]))<< "\n\n";

	}
}
