#include<iostream>
#include<cstring>
#include<set>
using namespace std;
#define N 100

struct Node{
	int a[N], ar = 0;
};

int fake(set<int> s,int n){
	int count = 0, ans = 0;
	for (int i = 1; i <= n; i++)
		if (!s.count(i)){ ans = i; count++; }
	if (count > 1)return -1;
	return ans;
}

int fake2(set<int> s, Node* f,int fr, int n){
	for (int fi = 0; fi < fr; fi++){
		int count = 0, ans = 0;
		for (int fj = 0; fj < f[fi].ar; fj++)
			if (!s.count(f[fi].a[fj])){ ans = f[fi].a[fj]; count++; }
		if (count == 1)return ans;
	}
	return 0;
}

int main() {
	int m, n, k, mi = 0, p, found;
	char ch;
	for (cin >> m; mi < m; mi++){
		int a[N], fr = 0;
		Node f[N];
		set <int> e;
		cin >> n >> k;
		for (int ki = 0; ki < k; ki++){
			cin >> p;
			for (int pi = 0; pi < 2*p; pi++)cin >> a[pi];
			cin >> ch;
			if (ch == '='){
				for (int pi = 0; pi < 2*p; pi++)
					e.insert(a[pi]);
			}else{
				for (int pi = 0; pi < 2 * p; pi++)
					f[fr].a[pi] = a[pi];
				f[fr].ar = 2 * p;
				fr++;
			}
		}
		if (mi)printf("\n");
		found = fake(e, n);
		printf("%d\n",  found>0?found:fake2(e, f,fr, n));
	}
}