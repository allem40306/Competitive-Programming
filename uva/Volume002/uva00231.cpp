#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define S 100005

int main() {
	int n, m[S], t = 1;
	while (cin >> n, n != -1) {
		memset(m, 0, sizeof(m));
		int p = 1;
		m[0] = n;
		while (cin >> n, n != -1)m[p++] = n;
		int lis[S] = { 0 };
		int maxx = 0;
		for (int i = 1;i <= p;i++) {
			for (int j = 0;j < i;j++)
				if (m[i] <= m[j])lis[i] = max(lis[i], lis[j] + 1);
			maxx = max(maxx, lis[i]);
		}
		if (t > 1)cout << endl;
		printf("Test #%d:\n maximum possible interceptions: %d\n", t++, maxx);
	}
}