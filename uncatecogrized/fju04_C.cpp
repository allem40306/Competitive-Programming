#include <iostream>
#include <algorithm>
using namespace std;
const int N = 50005;
struct Data {
	int L, R;
	bool operator<(const Data& rhs)const {
		if (L != rhs.L)return L < rhs.L;
		return R < rhs.R;
	}
};

int main() {
	int n;
	Data a[N];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].L >> a[i].R;
	}
	sort(a, a + n);
	int ansL = a[0].L, ansR = a[0].R;
	for (int i = 1; i < n; i++) {
		if (a[i].L <= ansR) {
			ansR = max(ansR, a[i].R);
		} else {
			cout << ansL << ' ' << ansR << '\n';
			ansL = a[i].L;
			ansR = a[i].R;
		}
	}
	cout << ansL << ' ' << ansR << '\n';
}
