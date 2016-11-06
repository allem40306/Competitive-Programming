#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#define N 10005
int ti = 0, n, m, a, x, y, z;
struct Treap{
	Treap *l, *r;
	int val, sz, pri;
	Treap(int _val, int _sz) :
		val(_val), sz(_sz), l(NULL), r(NULL), pri(rand()) {}
	Treap(){};
};
inline int mx
Treap* merge(Treap* a, Treap* b){
	if (!a || !b)return a ? a : b;
	if (a->pri > b->pri){
		a->r = merge(a->r, b);
		return a;
	}
	else{
		b->l = merge(a, b->l);
		return b;
	}
}
void split(Treap* t, int k, Treap *&a, Treap *&b){
	if (!t)a = b = NULL;
	else if (t->sz <= k){
		a = t;
		split(t->r, k, a->r, b);
	}
	else {
		b = t;
		split(t->l, k, a, b->l);
	}
	return;
}


int main(){
	while (cin >> n >> m){
		Treap* t = NULL;
		for (int i = 0; i<n; i++){
			cin >> a;
			t = merge(t, new Treap(i + 1, a));
		}
		cout << 1;
	}
}
