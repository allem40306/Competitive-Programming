#include <iostream>
#include <algorithm>
using namespace std;
#define N 20000
#define M 1e+20
#define ULL unsigned long long
ULL t, n, a[N], b[N];

void init(){
	for (int i = 0; i < N; i++)
		a[i] = M;
}

template<typename T>
T GCM(T a, T b){
	T c;
	while (c = b%a){ b = a; a = c; }
	return a;
}

int main(){
	while (cin >> t){
		for (int ti = 0; ti < t; ti++){
		init();
		cin >> n;
		for (int i = 0; i < n; i++)cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n - 1; i++)b[i] = a[i + 1] - a[i];
		sort(b, b + n-1);
		ULL g = GCM(b[0], b[1]);
		for (int j = 2; j < n-1; j++)
			g = GCM(g, b[j]);
		cout << g << endl;
		}
	}
}