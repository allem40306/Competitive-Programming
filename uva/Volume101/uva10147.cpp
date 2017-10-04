#include <iostream>
using namespace std;
#define N 1000
#define pd(x,y) (x-y)*(x-y)
#define MAX 1e+9

int main(){
	int n, m, ti;
	cin >> ti;
	while (ti--){
		static int x[N], y[N], w[N][N], i, j, v1, v2;
		cin >> n;
		for (i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				w[i][j] = w[j][i] = pd(x[i], x[j]) + pd(y[i], y[j]);
		cin >> m;
		for (i = 0; i < m; i++){
			cin >> v1 >> v2;
			w[v1-1][v2-1] = w[v2-1][v1-1] = 0;
		}
		int p[N], d[N], mi, v;
		bool visit[N], num = false;
		for (i = 0; i < n; i++)visit[i] = false;
		for (i = 0; i < n; i++){ d[i] = MAX; p[i] = -1; }
		d[0] = 0;
		for (int u = 0; u < n; u++){
			mi = MAX;
			for (i = 0; i < n; i++)
				if (!visit[i] && d[i] < mi){
				v = i; mi = d[i];
				}
			visit[v] = true;
			if (mi > 0){
				printf("%d %d\n", v + 1, p[v] + 1);
				num = true;
			}
			for (i = 0; i < n; i++){
				if (!visit[i] && d[i] - w[v][i] > 0){
					d[i] = w[v][i];
					p[i] = v;
				}
			}
		}
		if (!num) printf("No new highways need\n");
		if (ti)printf("\n");
	}
} 
