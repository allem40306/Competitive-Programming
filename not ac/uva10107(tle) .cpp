#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
#define N 10010

int main(){
	int n, c = 0, m[N];
	while (cin >> m[c++]){
		sort(m, m + c);
		if (c % 2)cout << m[c / 2] << endl;
		else cout << (m[c / 2] + m[c / 2 - 1]) / 2 << endl;
	}
}