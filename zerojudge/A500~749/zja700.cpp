#include <iostream>
using namespace std;
#define ULL unsigned long long
#define M 64

int main(){
	ULL a[M] = { 1 };
	for (int i = 1; i < M; i++)a[i] = a[i - 1] * 2;
	int n, m;
	while (cin >> n >> m){
		cout << a[(n - 1) * 8 + (m - 1)] << endl;
	}
}