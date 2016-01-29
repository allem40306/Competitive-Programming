#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool comp(char a,char b){
	if (toupper(a) != toupper(b))
		return toupper(a) < toupper(b);
	return a < b;
}

void perm(int i,string s){
	if (i == s.size() - 1)
		cout << s << endl;
	else {
		perm(i + 1, s); 
		for (int j = i + 1; j != s.size();j++){
			if (s[i] == s[j]) continue;
			swap(s[i], s[j]);
			perm(i + 1, s);
		}
	}
}

int main(){
	int n;
	string s;
	cin >> n;
	while (n--){
		cin >> s;
		sort(s.begin(), s.end(), comp);
		perm(0, s);
	}
}
