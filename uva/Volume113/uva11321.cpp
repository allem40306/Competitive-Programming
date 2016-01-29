//11321 - Sort! Sort!! and Sort!!! (by Snail)
#include <iostream>
#include <algorithm>                            //for sort
using namespace std;

int m;                                          //cmp い璶ノm
//珿办
bool cmp(int a, int b) {
	if (a%m != b%m)                             //璝緇计ぃ单
		return a%m < b%m;                       // 緇计逼
	if ((a + b) % 2)                                //璝案
		return abs(a % 2) >abs(b % 2);                   // 计玡
	if (a % 2)                                    //计
		return a > b;                           // 玡
	return a < b;                               //玥玡
}

int main() {
	int i, n, a[10000];
	while (cin >> n >> m, n) {
		for (i = 0; i<n; i++)
			cin >> a[i];
		sort(a, a + n, cmp);
		cout << n << ' ' << m << endl;
		for (i = 0; i<n; i++)
			cout << a[i] << endl;
	}
	cout << "0 0\n";
}
