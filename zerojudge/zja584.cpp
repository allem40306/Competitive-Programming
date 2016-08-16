#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define N 1000
int r = 0;

struct peopple{
	string p;
	int f, depth;
	
}p[N];

void init(){
	for (int i = 0; i < N; i++){
		p[i].f = -1;
		p[i].p = "";
		}
	return;
}

int find(string s){
	for (int i = 0; i < r; i++)
		if (p[i].p == s)return i;
	p[r++].p = s;
	return r-1;
}

int main(){
	int n;
	while (cin >> n>>ws){
		string s, t;
		init();
		for (int i = 0; i < n; i++){
			int fn, en;
			getline(cin, s);
			stringstream ss(s);
			ss >> t;
			fn = find(t);
			while (ss >> t){
				en = find(t);
				p[en].f = fn;
			}
		}
		string a, b;
		cin >> a >> b;
		int an = find(a), bn = find(b), c;
		if (p[an].depth < p[bn].depth){ c = an; an = bn; bn = c; }
		bool vis[N] = { 0 }, out = 0;
		for (int an2 = an, i = 0; !out&&an2 != -1; i++, an2 = p[an2].f){
			p[an2].depth = i;
			vis[an2] = 1;
			if (an2 == bn){
				printf("%d\n", i);
				out = 1;
			}
		}
		for (int bn2 = bn, i = 0; !out; i++, bn2 = p[bn2].f){
			if (vis[bn2]){
				printf("%d\n", i+p[bn2].depth);
				out = 1;
			}
		}
	}
}