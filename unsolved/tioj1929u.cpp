#include <iostream>
#include <vector>
using namespace std;
#define N 1000005
vector<int> v[N];
int djs[N][2], n, m, x, y, c[N];
//#define scanf scanf_s
void init(){
	for (int i = 0; i<N; i++){
		djs[i][0] = i;
		djs[i][1] = 1;
		c[i] = 0;
		v[i].clear();
	}
}

bool bi(int x, int y){
	for (int i = v[x].size(), j = 0; j<i; j++)
		if (v[x][j] == y)return 1;
	return 0;
}

void merge(int x, int y){
	v[x].push_back(y);
	c[y]++;
	if (bi(y, x)){
		n--;
		djs[y][0] = x;
		djs[x][1] += djs[y][1];
		djs[y][1] = 0;
		c[x]--;
		for (int i = 0, j = v[y].size(); i < j; i++)
			v[x].push_back(v[y][i]);
	}
	return;
}

void topo(int r, int i, int n){
	int ii=i, j, jj, x;
	for (int ni = 0; ni < n;ni++){
		i = ii;
		for (j = 0, jj = v[i].size(); j < jj; j++){
			x = v[i][j];x = djs[x][0];c[x]--;
			if (x!=i&&c[x]<=0){
				while (djs[x][1]--)printf(" %d", r);
				ii = x; r++;
			}
		}
	}
}

int main(){
	init();
	scanf("%d %d", &n, &m);
	for (int mi = 0; mi<m; mi++){
		scanf("%d %d", &x, &y);
		merge(x, y);
	}
	printf("%d\n1", n);
	for (x = 1; c[x]; x++);
	for (y = 1; y < djs[x][1]; y++)printf(" 1");
	topo(2, x, n - 1); printf("\n");
}
