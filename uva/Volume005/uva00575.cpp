#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	while (cin >> s, s != "0"){
		long a=0,b=1;
		int lens = s.size();
		for (int j = lens-1; j>=0; j--){
			a += b*int(s[j] - '0');
			b = 2 * b + 1;
		}
		cout << a << endl;
	}
}