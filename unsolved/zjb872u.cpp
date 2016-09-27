#include <iostream>
#include <iomanip>
#include <map>
#include <cstring>
using namespace std;
#define N 1000
map <double, int> ma;
map <double, int>::iterator it;
int t, ti = 0, n, ans;
bool c[N];
double a[N][2];

void init(){
	ans = 0;
	ma.clear();
	memset(c, 0, sizeof(c));
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i][0] >> a[i][1];
}

int main() {
	for (cin >> t; ti < t; ti++) {
		init();
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				ma[(a[j][1] - a[i][1]) / (a[j][0] - a[i][0])]++;
		it = ma.begin();
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if ((a[j][1] - a[i][1]) / (a[j][0] - a[i][0]) == it->first)
					c[i] = c[j] = 1;
		for (int i = 0; i < n; i++)
			if (c[i])ans++;
		printf("%d\n", ans);
	}
}