#include<iostream>
#include<set>
using namespace std;
#define N 100
int main() {
	int m, n, k, mi = 0, p;
	char ch;
	for (cin >> m; mi < m; mi++){
		int a[N], b[N];
		set <int> w;
		set<int>::iterator it;
		cin >> n >> k;
		for (int ni = 1; ni <= n; ni++)
			w.insert(ni);
		for (int ki = 0; ki < k; ki++){
			cin >> p;
			for (int pi = 0; pi < p; pi++)
				cin >> a[pi] >> b[pi];
			cin >> ch;
			if (ch == '=')
				for (int pi = 0; pi < p; pi++){
				it = w.find(a[pi]);
				if(*it<0)w.erase(it);
				it = w.find(b[pi]);
				if(*it<0)w.erase(it);
				}
		}
		if (w.size()>1)printf("0\n");
		else {
			it = w.begin();
			cout << *it << endl;
		}
	}
}