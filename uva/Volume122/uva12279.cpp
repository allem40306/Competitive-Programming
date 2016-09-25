#include <iostream>
using namespace std;


int main() {
	int a, b, ti = 1;
	while (cin >> a, a){
		int b, ans = 0;
		while (a--){
			cin >> b;
			ans += (b ? 1 : -1);
		}
		printf("Case %d: %d\n", ti++, ans);
	}
}