#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 1000000
int ox[N], p[N], pr, cut[120];

struct JumpingChampion{  //d ®t­È t ¦¸¼Æ
	int d, t;
}jc[N];

void PrimeTable(){
	ox[0] = ox[1] = 1;
	pr = 0;
	for (int i = 2; i < N; i++){
		if (!ox[i]) p[pr++] = i;
		for (int j = 0; i*p[j]<N&&j < pr; j++)
			ox[i*p[j]] = 1;
	}
}

int main(){
	PrimeTable();
	int n, l, u;
	cin >> n >> ws;
	while (n--){
		memset(cut, 0, sizeof(cut));
		cin >> l >> u;
		int i, j;
		for (i = 0; i < pr; i++){
			if (u < p[i + 1])break;
			if (p[i] >= l&&p[i + 1] <= u)
				cut[p[i + 1] - p[i]]++;
		}
		int mmax = 0, count = 0;
		for (int k = 0; k < 120; k++){
			if (cut[mmax] < cut[k])mmax = k;
		}
		for (int k = 0; k < 120; k++){
			if (cut[mmax] == cut[k])count++;
		}
		if (count>1||mmax<1)
			printf("No jumping champion\n");
		else printf("The jumping champion is %d\n",mmax);
	}
}