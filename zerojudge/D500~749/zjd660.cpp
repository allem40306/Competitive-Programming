#include <iostream>
#include <cstdio>
using namespace std;
#define max(x,y) x>y?x:y

int main(){
	int t, n, i = 1;
	for (cin >> t; i <= t; i++){
		cin >> n;
		int a, b;
		int up = 0, down = 0;
		cin >> a;
		while (--n){
			cin >> b;
			if (a < b)up++;
			else if (a > b)down++;
			a = b;
		}
		printf("Case %d: %d %d\n", i, up, down);
	}
}