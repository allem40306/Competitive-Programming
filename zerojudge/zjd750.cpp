#include <iostream>
#include <algorithm>                            //for sort
using namespace std;

int m;                                          //cmp 中要用到m
//故宣告為全域
bool cmp(int a, int b) {
	if (a%m != b%m)                             //若餘數不等
		return a%m < b%m;                       // 按餘數排序
	if ((a + b) % 2)                                //若一奇一偶
		return abs(a % 2) >abs(b % 2);                   // 奇數在前
	if (a % 2)                                    //同為奇數
		return a > b;                           // 大在前
	return a < b;                               //否則小在前
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