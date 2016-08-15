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
		p[i].f = p[i].depth = -1;
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
			if (p[fn].depth == -1)p[fn].depth = 0;
			while (ss >> t){
				en = find(t);
				p[en].f = fn;
				p[en].depth = p[fn].depth + 1;
			}
		}
		string a, b;
		cin >> a >> b;
		int an = find(a), bn = find(b), c;
		if (p[an].depth < p[bn].depth){ c = an; an = bn; bn = c; }
		int an2 = an, bn2 = bn;
		bool vis[N] = { 0 }, out = 0;
		while (!out&&an != -1){
			vis[an] = 1;
			if (p[an].f == bn2){
				printf("%d\n", p[an2].depth - p[bn2].depth);
				out = 1;
			}
			an = p[an].f;
		}
		while (!out){
			if (vis[bn]){
				out = 1;
				printf("%d\n",p[an2].depth + p[bn2].depth-p[bn].depth * 2);
			}
			bn = p[bn].f;
		}
	}
}