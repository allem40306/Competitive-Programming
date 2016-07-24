#include <iostream>
#include <algorithm>
using namespace std;
#define N 40000
int a[N], maxx, ar, t, n;

struct pay{
	int s, c, e;
}p[N];;

bool cmp(pay a, pay b){
	if (a.s != b.s)
		return a.s < b.s;
	return a.e < b.e;
}

void dp(int i, int m){
		{
			maxx = m>maxx ? m : maxx;
			for (int j = i + 1; j < n; j++){
				if (p[i].e < p[j].s)
				dp(j, m + p[j].c);
			}
		}
}

int main(){
	for (cin >> t; t; t--){
		cin >> n;
		for (int i = 0; i < N; i++)
			p[i].s = p[i].e = p[i].c = 0;
		for (int i = 0; i < n; i++)
			cin >> p[i].s >> p[i].e >> p[i].c;
		sort(p, p + n, cmp);
		a[N] = {}, maxx = ar = 0;
		for (int i = 0; i<n; i++)dp(0, p[i].c);
		printf("%d\n", maxx);
	}
}