#include <iostream>
using namespace std;
int main(){
	int num, bin[100], i;
	while (cin >> num){
		i = 0;
		while (num > 0){
			bin[i] = num % 2;
			num = num /2;
			i++;
		}
		for (int j = i - 1; j >= 0; j--){
			cout << bin[j];
		}
		cout << endl;
	}
}
