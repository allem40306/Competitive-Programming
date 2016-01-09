#include<iostream>
using namespace std;

int f91(int a){
	if (a <= 100) return  f91(f91(a + 11));
	return a - 10;
}

int main() {
	int n;
	while (cin >> n, n){
		cout << "f91(" << n << ") = " << f91(n) << endl;
	}
}