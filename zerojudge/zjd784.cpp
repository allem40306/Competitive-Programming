//d784. 連續元素的和 by Snail
#include <iostream>
using namespace std;

int main () {
	int tc, n, s, a, maxs;
	cin >> tc;
	while (tc--) {
		cin >> n >> s;							//輸入第一個數字
		maxs = -1000000;
		while (--n) {							//輸入剩下的n-1個數字
			cin >> a;
			s = max (a, a+s);					//當前最大和
			maxs = max (s, maxs);				//全域最大和
		}
		cout << maxs << endl;
	}
}