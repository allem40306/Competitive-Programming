#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
#define N 2000
#define M 26
int n, h, w, ni = 1;
bool vis[N][N];
string s[N];

struct alpha{
	int r, n;
}alp[M];

struct loc{
	int x, y;
	loc(int x, int y) :x(x), y(y){}
}k = loc(0, 0);

void init(){
	for (int i = 0; i < M; i++)
		alp[i].r = i, alp[i].n = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			vis[i][j] = 0;
	return;
}

void dfs(char r, int x, int y){
	stack <loc>st; st.push(loc(x, y));
	int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
	while (!st.empty()){
		loc k = st.top(); st.pop();
		for (int i = 0; i < 4; i++){
			int a = k.x + dx[i], b = k.y + dy[i];
			if (a >= 0 && a < h&&b >= 0 && b <= w&&s[a][b] == r&&!vis[a][b]){
				st.push(loc(a, b));
				vis[a][b] = 1;
			}
		}
	}
	return;
}

bool cmp(alpha a, alpha b){
	if (a.n != b.n)
		return a.n>b.n;
	return a.r < b.r;
}

int main(){
	for (cin >> n; ni <= n; ni++){
		init();
		cin >> h >> w;
		for (int i = 0; i < h; i++)cin >> s[i];
		for (int j = 0; j < h; j++)
			for (int k = 0; k < w; k++)
			if (!vis[j][k]){
			vis[j][k] = 1;
			alp[s[j][k] - 'a'].n++;
			dfs(s[j][k],j,k);
			}
		sort(alp, alp + M, cmp);
		printf("World #%d\n", ni);
		int ar = 0;
		while (alp[ar].n){
			printf("%c: %d\n", char('a' + alp[ar].r), alp[ar].n);
			ar++;
		}
	}
}