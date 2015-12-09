#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000000
int ox[N], p[N], pr;

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

bool comp(JumpingChampion a, JumpingChampion b){
	if (a.t != b.t)
		return a.t > b.t;
	return 0;
}

int main(){
	PrimeTable();
	int n;
	cin >> n >> ws;
	while (n--){
		int num = 0, l, u ,i, j;
		cin >> ws >> l >> u;
		for (int x = 0; x < N; x++){ jc[x].d = x; jc[x].t = 0; }
		for (i = 0; p[i] <= l; i++);
		for (j = i; p[j] <= u; j++);
		while (p[j]>u)j--;
		for (int y = i; y < j; y++) jc[p[y + 1] - p[y]].t++;
		sort(jc, jc +N ,comp);
		if (j - i < 3 || jc[0].t == jc[1].t)
			printf("No jumping champion\n");
		else printf("The jumping champion is %d\n",jc[0].d);
	}
}