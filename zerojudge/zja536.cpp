#include <iostream>
using namespace std;

int main(){
	int n, e, f, c;
	cin >> n;
	while (n--){
		int ans = 0;
		cin >> e >> f >> c;
		e += f;
		while (e / c){
			ans += e / c;
			e = e / c + e%c;
		}
		printf("%d\n", ans);
	}
}