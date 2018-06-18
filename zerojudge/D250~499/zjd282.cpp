#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define N 25
#define M 400
#define MIN(x,y) x<y?x:y

int main(){
	int n, m, cas = 1;
	while (cin >> n >> m, n){
		string na[N];
		int v1, v2, s;
		int i, j, k;
		int map[M][M];
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				map[i][j] = 1000000;
		for (i = 1; i <= n; i++)cin >> na[i];
		for (j = 1; j <= m; j++){
			cin >> v1 >> v2 >> s;
			map[v1][v2] = map[v2][v1] = s;
		}
		for (k = 1; k <= n; k++)
			for (i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if(i!=j)map[i][j] = map[j][i] = MIN(map[i][j], map[i][k] + map[k][j]);
		int a = 10000000, b = 0, ans;
		for (i = 1; i <= n; i++){
			for (j = 1; j <= n; j++){
				b += map[i][j];
			}
			if (a > b)ans = i, a = b;
			b = 0;
		}
		printf("Case #%d : ", cas++);
		cout << na[ans] << endl;
	}
}