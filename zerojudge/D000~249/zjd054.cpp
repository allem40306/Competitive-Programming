#include <iostream>
using namespace std;

int main(){
	long long int n, i[41] = { 1, 1, 5 };
	for (int j = 3; j < 42; j++)
		i[j] = i[j - 1] + i[j - 2] * 4 + i[j - 3] * 2;
	cin >> n;
	while (n--){
		int m; cin >> m;
		cout << i[m] << endl;
	}
}
