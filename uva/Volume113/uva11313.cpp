#include <iostream>
using namespace std;

int main(){
	int t, n, m;
	cin >> t;
	for (int i = 0; i < t; i++){
		int ans = 0;
		cin >> n >> m;
		printf((n - 1) % (m - 1) ? "cannot do this\n" : "%d\n", (n - 1) / (m - 1));
	}
}