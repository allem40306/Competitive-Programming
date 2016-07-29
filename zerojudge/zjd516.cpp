#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--){
		string s;
		cin >> s;
		int lens = s.size();
		for (int i = 0; i < lens; i++){
			int a = ((s[i] - 'A') + 3) % 26;
			cout << char('A' + a);
		}
		cout << endl;
	}
}