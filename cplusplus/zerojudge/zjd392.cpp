#include <iostream>
#include <string>
#include <sstream>
using namespace std;

long long int stn(string w) {
	long long int i = 0, j = 0, len = w.size();
	for (;i < len;i++){
		j *= 10;
		j+=int(w[i] - '0');
	}
	return j;
}

int main() {
	string s;
	while (getline(cin, s)) {
		stringstream ss(s);
		string w;
		long long int sum = 0;
		while (ss >> w)
			sum += stn(w);
		cout << sum << endl;
	}
}