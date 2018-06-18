#include <iostream>
using namespace std;
int main() {
	int n, c ,mx = 0;
	cin >> n;
	while (n--){
		cin >> c;
		if (c > mx)mx = c;
	}
	cout << mx;
}