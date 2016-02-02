#include <iostream>
#include <cstring>
using namespace std;
#define N 100010
int nn[N], buf[N];

struct nn[]

void search(int n, int k, int loc) {
	int low=0, high=n-1, mid;
	while (loc <= high&&loc == 0) {
		mid = (low + high) / 2;
		if (k == nn[mid])
			loc = mid;
		else if (k < nn[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
}

int main() {
	int n, k;
	while (cin >> n >> k) {
		memset(nn, 0, sizeof(nn));
		for (int i = 0;i < n;i++)cin >> nn[i];
		sol(0, n);
		search(n,k,0);
	}
}