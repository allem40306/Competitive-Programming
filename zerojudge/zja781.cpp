#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n, tn = 0;
	while (cin >> n, n){
		if (tn++)printf("\n");
		string s, ss;
		for (int i = 0; i < n; i++){
			s = '#' + s;
			s += '.';
		}
		s += s; s += s; ss = s;
		reverse(ss.begin(), ss.end());
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < n; j++)
				cout << s << endl;
			for (int j = 0; j < n; j++)
				cout << ss << endl;
		}
	}
}