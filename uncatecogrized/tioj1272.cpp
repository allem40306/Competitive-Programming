#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct Node {
	int val;
	int add;
	Node *lc, *rc;
	Node(): lc(NULL), rc(NULL), add(0), val(0) {};
	void pull() {
		val = lc->val + rc->val;
		return;
	}
	void push(int L, int R) {
		if (L == R)return;
		int M = (L + R) >> 1;
		lc->add += add;
		rc->add += add;
		lc->val += add * (M - L + 1);
		rc->val += val * (R - M);
		add = 0;
		return;
	}
};
int tot = 0, tin[N], tout[N];
vector<int>v[N];

void dfs(int s) {
	tin[s] = ++tot;
	for (auto x : v[s]) {
		dfs(x);
	}
	tout[s] = tot;
	return;
}

Node* build(int L, int R) {
	Node *node = new Node();
	if (L == R) {
		node->val = node->add = 0;
		return node;
	}
	int M = (L + R) >> 1;
	node->lc = build(L, M);
	node->rc = build(M + 1, R);
	node->pull();
	return node;
}

void modify(Node *node, int L, int R, int cl, int cr) {
	// cout << L << '-' << R << '\n';
	if (L > cr || R < cl)return;
	if (cl <= L && R <= cr) {
		node->add += 1;
		node->val += (R - L + 1);
		return;
	}
	node->push(L, R);
	int M = (L + R) >> 1;
	modify(node->lc, L, M, cl, cr);
	modify(node->rc, M + 1, R, cl, cr);
	node->pull();
	return;
}

int query(Node *node, int L, int R, int c) {
	if (L > c && R < c)return 0;
	if (L == R) return node->val;
	node->push(L, R);
	int M = (L + R) >> 1;
	return query(node->lc, L, M, c)
	       + query(node->rc, M + 1, R, c);
}

int main() {
	int n, m;
	bitset<N>c;
	cin >> n >> m;
	c.reset();
	for (int i = 1, x, y; i <= n; i++) {
		cin >> x;
		for (int j = 0; j < x; j++) {
			cin >> y;
			v[i].push_back(y);
			// cout<<i<<'-'<<y<<'\n';
			c[y] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (c[i])continue;
		dfs(i);
		break;
	}
	// for (int i = 1; i <= n; i++) {
	// 	cout << i << ' ' << tin[i] << ' ' << tout[i] << '\n';
	// }
	Node *root = build(1, n);
	for (int i = 0, x, y; i < m; i++) {
		cin >> x >> y;
		if (x) {
			cout << query(root, 1, n, tin[y]) % 2 << '\n';
		} else {
			modify(root, 1, n, tin[y], tout[y]);
		}
	}
}
