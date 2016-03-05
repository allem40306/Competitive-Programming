#include <iostream>
#include <cstdio>
using namespace std;
#define max(x,y) x>y?x:y
int main()
{
	int n, i, s, v, m; // n 飼料數, m 胃容量
	int c[1000] = { 0 };
	cin >> n;
	while (n){
		cin >> s >> v;
		i = 100;
		while ((i - s) >= 0){
			c[i] = max(c[i - s] + v, c[i]);
			//吃了以後飽足感比較大，c[i]就設定成新的(較大的)飽足感
			i--;
		}
		n--;
	}
	printf("%d\n", c[100]);
	return 0;
}