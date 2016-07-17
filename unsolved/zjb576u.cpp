#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define N 31
int a[N] = { 1 };
string s = "13";

int bulit(){
	int m = 3;
	for (int i = 1; i < N; i++){
		a[i] = m + 1;
		m *= 2;
	}
	return 0;
}

int main() {
	bulit();
	int t,k;
	cin >> t;
	while (t--){
		cin >> k;
		int k1 = k % 3, p = 1;
		if (k <= 3)cout << k << endl;
		else if (k1 == 2)cout << k1 << endl;
		else{
			for (int i = N - 1; i >= 0; i--){
				if (k - a[i] > 0){ k -= a[i]; p = 4 - p; }
			}
			if (k1)cout <<p<< endl;
			else cout << 4 - p << endl;
		}
	}
}