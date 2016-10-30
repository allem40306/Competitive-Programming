#include <iostream>
#include <iomanip>
#include <algorithm>
#define N 200
#define M 8
int ord[M] = { 4, 5, 3, 6, 2, 7, 1, 8 }, r[25][8], n;
struct score{
	int i;
	double sec;
}s[N];

bool cmp(score a, score b){
	return a.sec<b.sec;
}

void arrange(){
	int p = 0;
	for (int i = 0; i<4; i++){
		for (int j = 0; j<n / M; j++)
			r[j][ord[i * 2]-1] = s[p++].i;
		for (int j = n / M - 1; j >= 0; j--)
			r[j][ord[i * 2 + 1]-1] = s[p++].i;
	}
}

int main(){
	while (std::cin >> n){
		for (int i = 0; i<n; i++)
			std::cin >> s[i].i >> s[i].sec;
		std::sort(s, s + n, cmp);
		arrange();
		for (int i = 1; i <= n / M; i++){
			printf("%d", i);
			for (int j = 0; j<M; j++)
				printf(" %d", r[i-1][j]);
			printf("\n");
		}
	}
}
