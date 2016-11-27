#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 100005

struct r{ int x, y; }b[N];
bool cmp(r a, r b){ return a.x != b.x ? a.x<b.x : a.y<b.y; }
bool cmp2(r a, r b){ return a.y != b.y ? a.y>b.y : a.x>b.x; }
int bit[N];
int req(int x, int res){
	for (; x&&(res += bit[x]); x -= x&(-x));
	return res;
}
void add(int x, int n){ for (; x <= n; x += x&-x)bit[x]++; }
int main(){
	int n, m, i, ans = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i<n; i++)scanf("%d", &b[i].x);
	for (i = 0; i<n; i++)scanf("%d", &b[i].y);
	sort(b, b + n, cmp);
	for (i = 0; i<n; i++)b[i].x = i+1;
	sort(b, b + n, cmp2);
	memset(bit, 0, sizeof(bit));
	for (i = 0; i<n; i++){
		ans += req(b[i].x, 0);
		add(b[i].x, n);
	}
	printf("%d\n", ans);
}
