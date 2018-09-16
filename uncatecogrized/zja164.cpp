#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int s[N];
#define LL long long
#define Lc(x) (x<<1)
#define Rc(x) (x<<1)+1
#define PII pair<int,int>
#define MP make_pair
struct Node {
	int L, R, pre, suf;
	PII p;
} node[2 * N];

inline LL get_sum(PII a) {return s[a.second] - s[a.first - 1];}

bool is_max(PII a, PII b) {
	LL sa = get_sum(a), sb = get_sum(b);
	if (sa != sb) return sa >= sb;
	return  a < b;
}

PII maxp(Node a, Node b) {
	PII ans;
	if (is_max(a.p, b.p))ans = a.p;
	else ans = b.p;
	if (is_max(MP(a.suf, b.pre), ans))ans = MP(a.suf, a.pre);
	return ans;
}

int maxpre(Node a, Node b) {
	if (is_max(MP(a.L, a.pre), MP(a.L, b.pre)))
		return a.pre;
	return b.pre;
}

int maxsuf(Node a, Node b) {
	if (is_max(MP(a.suf, a.R), MP(a.suf, b.R)))
		return a.suf;
	return b.suf;
}

Node pull(Node a, Node b) {
	Node ans;
	ans.L = a.L;
	ans.R = b.R;
	ans.p = maxp(a, b);
	ans.pre = maxpre(a, b);
	ans.suf = maxsuf(a, b);
	cout << ans.L << ' ' << ans.R << ' ' << ans.pre << ' ' << ans.suf << ' ' << ans.p.first << ' ' << ans.p.second << ' ' << s[ans.p.second] - s[ans.p.first - 1] << '\n';
	return ans;
}

void bulid(int L, int R, int x) {
	// cout << L << " " << R << '\n';
	if (L == R) {
		node[x].L = node[x].R = node[x].pre = node[x].suf = L;
		node[x].p = MP(L, L);
		return;
	}
	int M = (L + R) >> 1;
	bulid(L, M, Lc(x));
	bulid(M + 1, R, Rc(x));
	node[x] = pull(node[Lc(x)], node[Rc(x)]);
	return;
}

Node query(int L, int R, int x) {
	cout << L << "~" << R << '\n';
	if (L <= node[x].L && node[x].R <= R)return node[x];
	int M = (node[x].L + node[x].R) >> 1;
	if (L <= M && M < R)return pull(query(L, M, Lc(x)), query(M + 1, R, Rc(x)));
	if (L <= M)return query(L, R, Lc(x));
	return query(L, R, Rc(x));
}

int main() {
	int n, q, x, y, ti = 1;
	while (cin >> n >> q) {
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
			s[i] += s[i - 1];
		}
		bulid(1, n, 1);
		cout << "Case " << ti++ << ":\n";
		for (int i = 0; i < q; i++) {
			cin >> x >> y;
			Node ans = query(x, y, 1);
			cout << ans.p.first << ' ' << ans.p.second << ' ' << s[ans.p.second] - s[ans.p.first - 1] << '\n';
		}
	}
}
