#include <iostream>
#include <vector>
using namespace std;
#define  N 26005
vector <int> r[N];
bool vis[N];
int a, b, ans;
char a1, b1;

void init(){
	for (int i = 0; i < N; i++){
		r[i].clear();
		vis[i] = 0;
	}		
	return;
}

void dfs(int stop, int pass, int trans){

}

int main() {
	int n;
	while (cin >> n){
		init();
		for (int i = 0; i < n; i++){
			cin >> a1 >> a >> b1 >> b;
			a += (a1 - 'A') * 1000;
			b += (b1 - 'A') * 1000;
			r[a].push_back(b);
			r[b].push_back(a);
		}
		cin >> a1 >> a >> b1 >> b;
		a += (a1 - 'A') * 1000;
		b += (b1 - 'A') * 1000;
		ans = 0;
		dfs(a, 0, 0);
	}	
}