#include <iostream>
#include <cstdio>
using namespace std;
#define max(x,y) x>y?x:y
int main()
{
	int n, i, s, v, m; // n �}�Ƽ�, m �G�e�q
	int c[1000] = { 0 };
	cin >> n;
	while (n){
		cin >> s >> v;
		i = 100;
		while ((i - s) >= 0){
			c[i] = max(c[i - s] + v, c[i]);
			//�Y�F�H�ṡ���P����j�Ac[i]�N�]�w���s��(���j��)�����P
			i--;
		}
		n--;
	}
	printf("%d\n", c[100]);
	return 0;
}