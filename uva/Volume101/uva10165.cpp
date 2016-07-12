#include <iostream>
using namespace std;
#define N 100

int main() {
	int n, m, o;
	while (cin >> n, n){
		cin >> m;
		for (int i = 1; i < n; i++){
			cin >> o;
			m ^= o;
		}
		if (m)printf("Yes\n");
		else printf("No\n");
	}
}