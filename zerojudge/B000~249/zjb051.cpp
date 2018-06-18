#include <iostream>
#include <algorithm> //for sort
#include <string>
using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a;
}

int main() {
	int n, i;		
	string s[100];
	while (cin >> n){
			for (int i = 0; i < n; i++)
				cin >> s[i];
			sort(s, s + n, cmp);
			for (int i = 0; i < n; i++)
				cout << s[i];
			cout << endl;
	}
}