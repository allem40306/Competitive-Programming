#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n, p[30], i,j;
	p[0] = 1;
	for (j = 1; j < 21; j++)
		p[j] = p[j - 1] * 2;
	cin >> n;
	for (i = 0; i <= n; i++){
		cout << "2^" << i << " = " << p[i] << endl;
	}
}