#include <iostream>
using namespace std;
#define N 100000000
int b[N], ans;

struct arr{
	int x, y;
};

int mod(int x, int y){
	int m;
	if (x < y)m = x, x = y, y = m;
	while (x%y){
		m = x%y, x = y, y = m;
	}
	return y;
}


void count(){
	ans = 0;
	for (int i = 1; i <= 60; i++)
		for (int j = 1; j <= 60; j++)
			if (i == 1 || j == 1 || mod(i, j) == 1)ans++;
}

int main() {
	count();
	static arr a[N];
	int ar = 1;
	a[1].x = a[1].y = 1;
	b[a[ar].x * 100 + a[ar].y] = ar;
	while (ans){
		ar++;
		if (ar % 2){
			a[ar].x = a[ar - 1].y;
			a[ar].y = a[ar - 1].x;
		}
		else{
			a[ar].x = a[ar / 2].x + a[ar / 2].y;
			a[ar].y = a[ar/2].y;
		}
		int mm=mod(a[ar].x, a[ar].y);
		a[ar].x /= mm, a[ar].y/=mm;
		b[a[ar].x * 100 + a[ar].y] = ar;
		if (a[ar].x <= 60 && a[ar].y <= 60)ans--;
	}
	int n, m;
	while (cin >> n >> m){
		int mm = mod(n, m);
		n/= mm, m /= mm;
		cout << b[n * 100 + m] << endl;
	}
}