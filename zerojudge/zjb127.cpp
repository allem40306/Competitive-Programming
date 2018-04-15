#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, s[50];
	s[1] = 1, s[0] = 1;
	for (int i = 2; i < 50; i++){
		s[i] = s[i - 2] + s[i - 1];
	}
	while (cin >> n){
		cout << s[n] << endl;;
	}
}