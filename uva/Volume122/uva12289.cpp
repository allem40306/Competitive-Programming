#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
int main(){
	string s;
	int n;
	cin >> n;
	while (n--){
		cin >> s;
		if (s.size() == 5)
			cout << "3\n";
		else if ((s[0] == 'o') + (s[1] == 'n') + (s[2] == 'e') >= 2)
			cout << "1\n";
		else cout << "2\n";
	}
}