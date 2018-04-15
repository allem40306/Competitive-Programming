#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string nts(int t) {
	int t2 = t % 10;
	string s = "";
	while (t) {
		s += char(t2 + 48);
		t /= 10;
		t2 = t % 10;
	}
	return  s;
}

string tran(string s) {
	int t = 1; char c = s[0]; string ss = "";
	for (int i = 0, l = s.size();i < l;i++) {
		if (c == s[i + 1])t++;
		else {
			ss += nts(t) + c;
			t = 1;
			c = s[i+1];
		}
	}
	return ss;
}

int main() {
	int n;
	string s[45] = { "1" };
	for (int i = 1;i < 45;i++)
		s[i] = tran(s[i - 1]);
	while (cin >> n)
		cout << s[n - 1] << endl;
}