#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string s;
	int m, a, b;
	cin >> m;
	while (m--){
		s = "";
		cin >> a >> b;
		for (int i = b; i < a; i++)
			s += '0';
		for (int j = b; j; j--)
			s += '1';
		do{
			cout << s << endl;
		} while (next_permutation(s.begin(), s.end()));
		cout << endl;
	}
}