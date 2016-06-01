#include <stdio.h> 
const int MAX_N = 20005;
const int MOD = 1000;
//在UVa使用库的abs居然WA，浪费好多时间  
inline int abs(int a) { return a < 0 ? -a : a; }

struct Subset{
	int p, w;
};

Subset subs[MAX_N];

int findParent(int x){
	if (subs[x].p != x)	{
		int p = subs[x].p;
		subs[x].p = findParent(subs[x].p);
		subs[x].w = (subs[x].w + subs[p].w);
	}
	return subs[x].p;
}

void initSubs(int N){
	for (int i = 1; i <= N; i++){
		subs[i].p = i;
		subs[i].w = 0;
	}
}

int main(){
	int T, N, i, j;
	char cmd;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		getchar();
		initSubs(N);
		while ((cmd = getchar()) && cmd != 'O'){
			if (cmd == 'E'){
				scanf("%d", &i);
				subs[i].p = findParent(i);
				printf("%d\n", subs[i].w);
			}
			else{
				scanf("%d %d", &i, &j);
				subs[i].w = (abs(j - i)) % MOD;
				subs[i].p = j;//不存在重复连线和更改parent，故此直接连就ok  
			}
			getchar();
		}
	}
	return 0;
}