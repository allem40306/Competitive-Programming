#include <iostream>
using namespace std;

int main(){
	int t, a, b, i;
	for (cin >> t, i = 1; i <= t; i++){
		int sum = 0;
		cin >> a >> b;
		for (int j = a; j <= b; j++){
			sum += j*(j % 2);
		}
		printf("Case %d: %d\n", i,sum);
	}
}