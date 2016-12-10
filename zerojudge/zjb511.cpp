#include <iostream>
#include <algorithm>
using namespace std;
#define N 5
#define M 100
int n, coin[N], m, pr;

struct poss{
	int a, b, c, d, e;
}p[100000];

bool cmp(poss a, poss b){
	if (a.a != b.a)return a.a < b.a;
	if (a.b != b.b)return a.b < b.b;
	if (a.c != b.c)return a.c < b.c;
	if (a.d != b.d)return a.d < b.d;
	return a.e < b.e;
}

void bulid(int a, int b, int c, int d, int e){
	p[pr].a = a;	p[pr].b = b;	p[pr].c = c;
	p[pr].d = d;	p[pr].e = e;	pr++;
	return;
}

void dp(int sum, int ar, int a1, int a2, int a3, int a4, int a5){
	if (sum>m)return;
	if (sum == m){ bulid(a1, a2, a3, a4, a5); return; }
	for (int i = ar; i < n; i++){
			if (i == 0)dp(sum + coin[i], i, a1+1, a2, a3, a4, a5);
			else if (i == 1)dp(sum + coin[i], i, a1, a2+1, a3, a4, a5);
			else if (i == 2)dp(sum + coin[i], i, a1, a2, a3+1, a4, a5);
			else if (i == 3)dp(sum + coin[i], i, a1, a2, a3, a4+1, a5);
			else dp(sum + coin[i], i, a1, a2, a3, a4, a5+1);
		}
	return;
}

int main(){
	while (cin >> n){
		pr = 0;
		for (int i = 0; i < n; i++)cin >> coin[i];
		cin >> m;
		dp(0, 0, 0, 0, 0, 0, 0);
		sort(p, p + pr, cmp);
		for (int i = 0; i < pr; i++){
			printf("(");
			for (int j = 0; j < n; j++){
				if (j == 0)printf("%d", p[i].a);
				else if (j == 1)printf(",%d", p[i].b);
				else if (j == 2)printf(",%d", p[i].c);
				else if (j == 3)printf(",%d", p[i].d);
				else printf(",%d", p[i].e);
			}
			printf(")\n");
		}
	}
}
