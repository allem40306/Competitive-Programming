#include <iostream>
#include <cstdio>
using namespace std;
#define max(x,y) x>y?x:y

int main(){
	int t, n, i = 1, a, mmax;
	for (cin >> t; i <= t; i++){
		cin >> n;
		mmax = -1;
		while (n--){
			cin >> a;
			mmax = max(mmax, a);
		}
		printf("Case %d: %d\n", i, mmax);
	}
}