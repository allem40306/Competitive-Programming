//a020: ®≠§¿√“¿À≈Á by Snail
#include <iostream>
using namespace std;

int main() {
	int a, b, sum, check, total;
	int city[26] = { 10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33 };
	while (cin >> a){
		sum = 0;
		check = a % 10;
		a = a / 10;
		for (int i = 1; i!=9; i++){
			sum+= i*(a % 10);
			a = a / 10;
		}
		for (int j = 0; j != 26; j++){
			total = 0;
			total = city[j] / 10 + (city[j] % 10 )* 9 + sum;
			if (((10 - (total % 10)) % 10) == check)
				cout << char('A' + j);
		}
		cout << endl;
	}
}
