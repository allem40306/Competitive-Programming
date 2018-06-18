#include<iostream>
using namespace std;
int main(){
	int f, sum;
	cout << "PERFECTION OUTPUT\n";
	while (cin >> f, f){
		cout << f << "  ";
		sum = 0;
		for (int i = 1; i <= f / 2; i++)
			if (f%i == 0)sum += i;
		if (sum == f)cout << "PERFECT\n";
		else cout << (sum <f ? "DEFICIENT\n" : "ABUNDANT\n");
	}
	cout << "END OF OUTPUT\n";
}