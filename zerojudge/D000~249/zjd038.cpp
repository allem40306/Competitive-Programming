#include <iostream>
using namespace std;

int main(){
	long long int n,i[50] = { 1, 2, 3 };
	for (int j = 3; j < 50; j++)
		i[j] = i[j - 1] + i[j - 2];
	while (cin >> n, n)
		cout << i[n - 1] << endl;
}
