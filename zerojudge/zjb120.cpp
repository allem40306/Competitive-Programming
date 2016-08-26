#include <iostream>
using namespace std;

int h(int x){
	if (x < 2 || x % 6 <= 1)return -1;
	if (x % 6 == 2 || x % 6 == 5)return 2;
	return 5;
}

int g(int x){
	if (x <= 2)return x*x - 1;
	return 2;
}

int f(int x){
	int hh = h(x);
	if (x > hh){
		int i = x < 5 ? 0 : 5;
		int r = x < 5 ? 1 : -1;
		for (; i <= x; i++)
			r -= h(i);
		return r;
	}
	if (x<hh)
		return f(g(x)) - g(x);
	return 1;
}

int main(){
	int n; 
	while (cin >> n){
		cout << f(n) << endl;
	}
}