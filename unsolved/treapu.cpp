#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Treap{
	Treap *l, *r;
	int val, key, pri;
	Treap(int _val, int _key):
		val(_val), key(_key), l(NULL), r(NULL), pri(rand()){}

}