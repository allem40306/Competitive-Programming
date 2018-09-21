#include <bits/stdc++.h>
using namespace std;

string cmp = "aeiou";
bool ok(char ch) {
	for (int i = 0; i < cmp.size(); i++) {
		if (ch == cmp[i])return 1;
	}
	return 0;
}

int main() {
	string s;
	while (getline(cin, s)) {
		bool alp = false;
		char tmp = ' ';
		for (int i = 0; i < s.size(); i++) {
			if (isalpha(s[i])) {
				if (!alp && !ok(tolower(s[i]))) {
					tmp = s[i];
					alp = true;
					continue;
				}
				alp = true;
				cout << s[i];
			} else {
				if (alp) {
					if (tmp != ' ') {
						cout << tmp;
						tmp = ' ';
					}
					cout << "ay";
				}
				alp = false;
				cout << s[i];
			}
		}
		if (tmp != ' ') {
			cout << tmp;
			tmp = ' ';
		}
		if(alp)cout << "ay";
		cout << '\n';
	}
}