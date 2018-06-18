#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define L 10005
vector<int>v[L];
bool p[L];//problem
#define  scanf scanf_s
bool que(int x){
	if (p[x])return 1;
	for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); it++){
		if (p[x] = que(*it))return 1;
	}
	return 0;
}

int main(){
	int m, n, l, q, i, x, y;
	for (i = 0; i < L; i++)v[i].clear();
	scanf("%d %d %d %d", &n, &m, &l, &q);
	for (i = 0; i < m; i++){
		scanf("%d %d", &x, &y);
		v[y].push_back(x);
	}
	memset(p, 0, sizeof(p));
	for (i = 0; i < l; i++){
		cin >> x;
		p[x] = 1;
	}
	for (i = 0; i < q; i++){
		cin >> y;
		que(y) ? printf("TUIHUOOOOOO\n") : printf("YA~~\n");
	}
}