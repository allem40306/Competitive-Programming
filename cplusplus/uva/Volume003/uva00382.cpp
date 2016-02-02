#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n;
	cout << "PERFECTION OUTPUT\n";
	while (cin >> n, n){
		int count = 0;
		for (int i = 1; i <= n / 2; i++)
			if (!(n%i))count += i;
		cout << setw(5) << n << "  ";
		if (n == count)cout << "PERFECT\n";
		else if (n > count)cout << "DEFICIENT\n";
		else cout << "ABUNDANT\n";
	}
	cout << "END OF OUTPUT\n";
}