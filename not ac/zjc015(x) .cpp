#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

string n_to_s(int n){
	string s = "";
	while (n){
		s = char((n % 10) + 48) + s;
		n /= 10;
	}
	return s;
}

int s_to_n(string s){
	int n = 0, j = s.size();
	for (int i = 0; i < j; i++)
		n = n * 10 + int(s[i] - '0');
	return n;
}

int main() {
	int n; 
	cin >> n;
	while (n--){
		string m;
		int cc = 1;
		cin >> m;
		string m1 = m;
		reverse(m1.begin(), m1.end());
		while (1){
			m = n_to_s(s_to_n(m) + s_to_n(m1));
			m1 = m;
			reverse(m1.begin(), m1.end());
			if (m1 == m)break;
			cc++;
		}
		cout << cc << ' ' << m << endl;
	}
}
