#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
#define N 100005
int n, m, i, y, x,bit[N] = {}; long long ans = 0; map <int, int> ma;
struct r{ int x, y; }b[N];
bool cmp(r a, r b){ return a.x != b.x ? a.x>b.x : a.y>b.y; }
int req(int x, int res){ for (; x; x -= x&(-x))res += bit[x]; return res; }
void add(int x){ for (; x <= m; x += x&(-x))bit[x] += 1; }
int main(){
	scanf("%d %d", &n, &m);
	for (i = 0; i<n; i++)scanf("%d", &b[i].x);
	for (i = 0; i<n; i++)scanf("%d", &b[i].y), ma[b[i].y] = 1;
	sort(b, b + n, cmp); i = 1;
	for (map<int, int>::iterator it = ma.begin(); it != ma.end(); it++)it->second = ++i;
	for (m = i, i = 0; i < n; i++){x = ma[b[i].y] - 1; ans+=req(x, 0); add(x + 1);	}
	printf("%lld\n", ans);
}

