#include <iostream>
#include <iomanip>
#include <map>
using namespace std;
#define N 1000
map <double, int> ma;
map <double, int>::iterator it;
int t, ti = 0, n, ans;
double a[N][2];

void init(){
	ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i][0] >> a[i][1];
}

int main() {
	for (cin >> t; ti < t; ti++) {
		init();
		if (n == 1)printf("1\n");
		else {
			for (int i = 0; i<n; i++){
				ma.clear();
				for (int j = 0; j<n; j++){
					if (i != j)
						ma[(a[j][1] - a[i][1]) / (a[j][0] - a[i][0])]++;
				}
				it = ma.begin();
				if (it->second >ans)ans = it->second;
			}
			printf("%d\n", ans + 1);
		}
	}
}
