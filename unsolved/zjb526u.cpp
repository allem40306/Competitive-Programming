#include <iostream>
#include <algorithm>
using namespace std;
#define N 100500

struct ft{
	int f, t;
};

bool cmp(ft a, ft b){
	if (a.f != b.f)
		return a.f < b.f;
	return a.t < b.t;
}

int main() {
	int n, m;
	while (cin >> n){
		cin >> m;
		static ft a[N];
		for (int i = 0; i < m; i++)
			cin >> a[i].f >> a[i].t;
		sort(a, a + n, cmp);
		for (int i = 0; i < m; i++){

		}
	}
}