#include <iostream>   
using namespace std;

int main(){
	int t, ti = 1;
	for (cin >> t; ti <= t; ti++){
		int k, h, m, ans = 10000, h1, m1, mm;
		char ch;
		cin >> k>> h >> ch >> m ;
		for (int i = 0; i < k; i++){
			cin >> h1 >> ch >> m1 >> mm;
			int sum = h1 * 60 + m1 - (h * 60 + m);
			sum = (sum>0 ? sum : sum + 1440) + mm;
			if(sum < ans)ans = sum;
		}
		printf("Case %d: %d\n", ti, ans);
	}
}