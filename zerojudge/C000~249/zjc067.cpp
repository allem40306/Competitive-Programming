#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, i, h[50], a, m, tc = 1;                //陣列 h 要有 50 個元素
	while (cin >> n, n) {
		a = 0;
		for (i = 0; i<n; i++) {
			cin >> h[i];                        //輸入高度
			a += h[i];                          //並加總
		}
		a /= n;                                 //求平均高度
		m = 0;                                  //m(oves)--移動個數
		for (i = 0; i<n; i++)
			m += max(0, h[i] - a);             //超出平均高度的個數
		cout << "Set #" << tc++ << endl;        //依題意要求輸出
		cout << "The minimum number of moves is " << m << ".\n\n";
	}
}
