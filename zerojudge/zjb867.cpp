#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

int main() {
	string s, t, ans = "{";
	bool f = 1;
	while (getline(cin, s)) {
		if (s == "end") { ans += "}"; f = 0; }
		else {
			stringstream ss(s);
			ss >> s; ss >> s; ss >> t;
			if (!f)  ans += ",";
			else f = 0;
			ans += s + ':';
			if (t == "newJSONObject") {
				ans += '{'; f = 1;
			}
			else ans += t;
		}
	}
	cout << ans;
}