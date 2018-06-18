#include <iostream>
#include <vector>
using namespace std;

vector <int> m[20001];
int n, maxnp = 0, maxv;

int traverse(int v, int s){
	int i, j;
	vector <int> st;
	st.push_back(n - 1);
	for (i = 0; i != m[v].size();i++)
		if (m[v][i] != s){
		st.push_back(traverse(m[v][i],v));
		st[0] -= st[st.size() - 1];
		}
	int np = 0;
	for (i = 1; i != st.size(); i++)
		for (j = 0; j < i; j++)
			np += st[i] * st[j];
	if ( np>maxnp || np == maxnp && v < maxv){
		maxnp = np; 
		maxv = v;
	}
	return n - st[0];
}

int main(){
	int i, v, u;
	cin >> n;
	for (int i = 1; i < n; i++){
		cin >> v >> u;
		m[u].push_back(v);
		m[v].push_back(u);
	}
		traverse(1, 0);
		cout << maxv << ' ' << maxnp << endl;
}
