#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
#include <string>
using namespace std;

map<string, int>cnt;
vector<string>word;

string repr(string r){
	for (int i = 0,len = r.size(); i < len; i++)
		r[i] = tolower(r[i]);
	sort(r.begin(), r.end());
	return r;
}

int main() {
	string s, r;
	while (cin >> s,s[0]!='#'){
		word.push_back(s);
		r = repr(s);
		if (!cnt.count(r))cnt[r] = 0;
		cnt[r] ++;
	}
	vector<string>ans;
	for (int i = 0, len = word.size(); i < len; i++)
		if (cnt[repr(word[i])] == 1)ans.push_back(word[i]);
	sort(ans.begin(), ans.end());
	for (int j = 0, len = ans.size(); j < len; j++)
		cout << ans[j] << endl;
}