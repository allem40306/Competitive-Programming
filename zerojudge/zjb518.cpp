#include <iostream>
using namespace std;
#define N 80

struct fe{
	int f, e;
}p[N];

void init(){
	for (int i = 0; i < N; i++)
		p[i].f = p[i].e = -1;
	return;
}

int main(){
	int n, ni = 0, m, i, j;
	for (cin >> n; ni < n; ni++){
		init();
		char ch;
		cin >> m;
		for (int mi = 0; mi < m; mi++){
			cin >> i >>ch>> j;
			if (j == 99){ p[i].f = -2; }
			else{ p[i].f = j; p[j].e = i; }
		}
		if (ni)printf("\n");
		for (i = 0; i < m; i++){
			if (p[i].e == -1){
				int ii = i, ans[N], ansr = 0;
				while (p[ii].f!=-2&&p[p[ii].f].f != -2){
					ans[ansr++] = p[ii].f;
					ii = p[ii].f;
				}
				printf("%d", i);
				if (!ansr)printf(":N\n");
				else{
					printf(":{");
					for (int ai = 0; ai < ansr; ai++)
						printf("%s%d", ai ? "," : "", ans[ai]);
					printf("}\n");
				}
			}
		}
	}
}