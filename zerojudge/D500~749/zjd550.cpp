#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	int n, m;
	while (cin >> n >> m){
		vector <int> e[10001];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++){
			int x; cin >> x;
			e[i].push_back(x);
			}
		sort(e, e + n);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++)
				cout << e[i][j] << ' ';
			cout << endl;
		}
	}
}