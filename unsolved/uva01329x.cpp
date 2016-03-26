#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define N 20010
#define abs(x) x>=0?x:-x
int p[N], d[N];

void init(int n){
	memset(d, 0, sizeof(d));
	for (int i = 0; i < n; i++)
		p[i] = i;
}

int find(int x){
	if (p[x] == x)
		return x;
	int tmp = p[x];
	p[x] = find(p[x]);
	d[x] += d[tmp];
	return p[x];
}

int main() {
	int t;
	while (cin >> t){
		int n, a, b;
		char ch;
		cin >> n;
		init(N);
		while (cin >> ch, ch != 'O'){
			if (ch == 'E'){
				cin >> a;
				find(a);
				printf("%d\n", d[a]);
			}
			else {
				cin >> a >> b;
				int fa = find(a);
				int fb = find(b);
				if (fa != fb){
					p[fa] = fb;
					d[a] = abs(a-b)% 1000 + d[b] - d[a];
				}
			}
		}
	}
}