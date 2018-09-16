#include <iostream>
#include <vector>
using namespace std;
const int N = 105;
int main() {
	int n, a[N], b[N];
	vector<int>v, w;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (a[i] > b[i]) {
			for (int j = 0; j < a[i] - b[i]; j++) {
				v.push_back(i);
			}
		} else if (a[i] < b[i]) {
			for (int j = 0; j < b[i] - a[i]; j++) {
				w.push_back(i);
			}
		}
	}
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ' << w[i] << '\n';
	}
}
