#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define N 5000
#define SZ(x) x.size()
int t, n, vis[N];

struct employ{
	int i, a, b, c;
}e[5000];

void init(){
	for (int i = 0; i < N; i++){
		e[i].i = i; vis[i] = 0;
	}
}

bool cmp(employ a,employ b){
	if (a.a != b.a)
		return a.a >= b.a;
	if (a.b != b.b)
		return a.b >= b.b;
	return a.c > b.c;
}

int who(int s){
	for (int i = 0; i < n; i++){
		if (e[i].i == s-1)return i;
	}
}

int bfs(int s){
	int ans = 1;
	stack<int> st;
	st.push(s);
	while (!st.empty()){
		int k = st.top(); st.pop(); vis[k] = 1;
		for (int i = k + 1; i < n; i++){
			if (e[i].a == e[s].a)continue;
			if (!vis[i] && e[i].c < e[k].b){
				vis[i] = 1; st.push(i); ans++;
			}
		}
	}
	return ans;
}

int main(){
	int ti = 0, s;
	for (cin >> t; ti < t;ti++){
		cin >> n; init();
		for (int i = 0; i < n; i++)
			cin >> e[i].a >> e[i].b >> e[i].c;
		sort(e, e + n, cmp);
		cin >> s;
		printf("%d\n",bfs(who(s)));
	}}