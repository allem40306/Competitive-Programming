#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;
#define N 100

int main() {
	string s, t;
	set<string> sos;
	while (cin >> s){
		for (int i = 0, len = s.size(); i < len; i++)
			if (isalpha(s[i]))s[i] = tolower(s[i]);
			else s[i] = ' ';
			stringstream ss(s);
			while (ss >> t)sos.insert(t);
	}
	for (set<string>::iterator it = sos.begin(); it != sos.end(); it++)
		cout << *it << endl;
}