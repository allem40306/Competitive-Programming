#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	string s, st[9] = {"0","1","21","321","4321","54321","654321","7654321","87654321"};
	int n;
	while (cin >> n){
		s = st[n];
		cout << s << endl;
		while (prev_permutation(s.begin(), s.end()))
			cout << s << endl;
	}
}

