#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int ti = 0;
struct Treap{
	Treap *l, *r;
	int val, size, pri;
	Treap(int _val) :
		val(_val), size(1) , l(NULL), r(NULL), pri(rand()) {}
	Treap(){};
};
int Size(Treap* t){return t?t->size:0;}
void pull(Treap* t){
	t->size=1+Size(t->l)+Size(t->r);
}
Treap* merge(Treap* a, Treap* b){
	if (!a || !b)return a ? a : b;
	if (a->pri > b->pri){
		a->r = merge(a->r, b);
		pull(a);
		return a;
	}
	else{
		b->l = merge(a, b->l);
		pull(b);
		return b;
	}
}
void split(Treap* t, int k, Treap *&a, Treap *&b){
	if (!t)a = b = NULL;
	else if (Size(t->l)+1 <= k){
		a = t;
		split(t->r, k, a->r, b);
		pull(a);
	}
	else {
		b = t;
		split(t->l, k, a, b->l);
		pull(b);
	}
	return;
}
