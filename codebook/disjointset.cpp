#include <iostream>
#include <cstdio>
using namespace std;
#define N 10000

struct disjointset{
	int p[N];
	void init(){
		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	int find(int x){
		return x == p[x] ? x : find(p[x]);
	}
	void Union(int a, int b){
		p[find(a)] = find(b);
	}
}djs;

int main() {
}