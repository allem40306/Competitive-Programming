#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define N 500
#define M 100000000
int ans[N] = { 1 };
int at = 28;

void bulit(){
	for (int i = 0; i <= 27; i++) {
		if (i) ans[i] = ans[i - 1] * 2;
		ans[at] = ans[i] * 5;
		while (ans[at] <= 100000000){
			int t = ans[at] * 5;
			ans[++at] = t;
		}
	}
}

int main(){
	bulit();
	int m;
	cin >> m;
	while (m--){
		int n, t = 0, i = 0;
		cin >> n;
		for (; i < at; i++)
			if (ans[i] <= n)t++;
		cout << t-1 << endl;
	}
}