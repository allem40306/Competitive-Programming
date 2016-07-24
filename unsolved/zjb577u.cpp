#include <iostream>
#include <algorithm>
using namespace std;
#define N 20000
int a[N] = {}, ans = 0;

struct pay{
	int s, c, e;
};

bool cmp(pay a, pay b){
	if (a.s != b.s)
		return a.s < b.s;
	return a.e < b.e;
}

int check(int i){
	if (a[i]||i == 0)return a[i];
	a[i] = check(i-1);
}

int main(){
	int t, n;
	pay p[N];
	for (cin >> t; t; t--){
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> p[i].s >> p[i].e >> p[i].c;
		sort(p, p + n, cmp);
		a[N] = {}, ans = 0;
		for (int i = 0; i < n; i++){
			check(p[i].s);
			if (a[p[i].e] < a[p[i].s] + p[i].c){
				a[p[i].e] = a[p[i].s] + p[i].c;
				if (ans < a[p[i].e])ans = a[p[i].e];
			}		
		}
		printf("%d\n", ans);
	}
}