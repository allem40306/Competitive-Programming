#include <iostream>
#include <string>
using namespace std;

int dp(int x){
	int ans = 0;
	while (x){
		ans += x % 2;
		x /= 2;
	}
	return ans;
}

int t(int x){
	int m = 1, ans = 0;
	while (x){
		ans += x % 10 * m;
		x /= 10;
		m *= 16;
	}
	return ans;
}

int main(){
	int n;
	while (cin >> n){
		for (int nn = 0; nn < n; nn++){
			int m;
			cin >> m;
			int b1 = dp(m);
			int b2 = dp(t(m));
			printf("%d %d\n", b1, b2);
		}
	}
}