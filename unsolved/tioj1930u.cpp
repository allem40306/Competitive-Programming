#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 2000005
struct line{ long long f, b; }arr[N];
static long long t, ti = 0, n, m, a1, k, a, b, c, res, pr, p[N];
//#define scanf scanf_s

void ins(int a, int b, int c){
	if (c == 1){
		arr[a].f = arr[b].f;
		arr[arr[b].f].b = a;
		arr[a].b = b;
		arr[b].f = a;
	}
	else{
		arr[a].b = arr[b].b;
		arr[arr[b].b].f = a;
		arr[a].f = b;
		arr[b].b = a;
	}
}

void modfiy(int a, int b, int c){
	arr[arr[a].b].f = c;
	arr[c].b = arr[b].b;
	arr[arr[c].f].b = a;
	arr[a].f = arr[c].f;
	arr[c].f = a;
	arr[b].b = c;

}

void give(int a, int b, int c){
	if (c == 1){
		int aa = arr[a].b;
		while (b--){
			p[pr++] = a;
			if (arr[a].f <= 0)break;
			a = arr[a].f;
		}
		if (b>0)res += b;
		if (aa>0)arr[aa].f = arr[a].f;
		if (arr[a].f>0)arr[arr[a].f].b = aa;
	}
	else{
		int aa = arr[a].f;
		while (b--){
			p[pr++] = a;
			if (arr[a].b <= 0)break;
			a = arr[a].b;
		}
		if (b>0)res += b;
		if (aa>0)arr[aa].b = arr[a].b;
		if (arr[a].b>0)arr[arr[a].b].f = aa;
	}
}

int main(){
	for (scanf("%lld", &t); ti < t; ti++){
		res = pr = 0;
		for (long long i = 0; i < N; i++)arr[i].f = arr[i].b = -1;
		scanf("%lld %lld %lld", &n, &m, &a1); arr[a1].f = arr[a1].b = -2;
		for (long long mi = 0; mi < m; mi++){
			scanf("%lld %lld %lld %lld", &k, &a, &b, &c);
			if (k == 1)ins(a, b, c);
			else if (k == 2)modfiy(a, b, c);
			else give(a, b, c);
		}
		printf("%lld\n", res);
		for (long long i = 0; i<n; i++)
			printf("%lld\n", p[i]);
	}
}
