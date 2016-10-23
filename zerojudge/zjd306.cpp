#include <iostream>
#include <string>
using namespace std;

int bti(string s){
	int lens = s.size(), r = 0;
	for (int i = 0; i < lens; i++)
		r = r * 2 + (s[i] == '0' ? 0 : 1);
	return r;
}

int main() {
	int t, ti = 1;
	string s1, s2;
	for (cin >> t; ti <= t; ti++){
		cin >> s1 >> s2;
		int n1 = bti(s1), n2 = bti(s2), t;
		if (n1 < n2)t = n1, n1 = n2, n2 = t;
		while (t = n1%n2)n1 = n2, n2 = t;
		if (n2 != 1)printf("Pair #%d: All you need is love!\n", ti);
		else printf("Pair #%d: Love is not all you need!\n", ti);
	}
}