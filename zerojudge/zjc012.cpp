#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define N 128

struct alp{
	int r, n;
}a[N];

void init(){
	for (int i = 0; i < N; i++){
		a[i].r = i;
		a[i].n = 0;
	}
	return;
}

bool cmp(alp a, alp b){
	if (a.n != b.n)
		return a.n < b.n;
	return a.r > b.r;
}

int main(){
	string s;
	int tn = 0;
	while (getline(cin,s)){
		init();
		int len = s.size();
		for (int i = 0; i < len; i++)
			a[s[i]].n++;
		sort(a, a + N, cmp);
		if (tn++)printf("\n");
		for (int i = 0; i < N; i++)
			if (a[i].n)
				printf("%d %d\n", a[i].r, a[i].n);
	}
}