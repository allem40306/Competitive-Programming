#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define N 11
int a[N] = {1};

int main(){
	string s;
	int n;
	for (int i = 1; i < N; i++)a[i] = a[i - 1] * 2;
	while (cin >> s >> n){
		int len = s.size(), t = 0;
		for (int j = 0; j < len; j++){
			t = t * 10 + (s[j] - '0');
			t %= a[n];
		}
		if (t){
			printf("可惡!!算了這麼久");
			cout << s;
			printf("竟然無法被2的%d次整除\n", n);
		}
		else {
			printf("YA!!終於算出");
			cout << s;
			printf("可被2的%d次整除了!!\n",n);
		}
	}
}