#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define N 102

int f(string s){
	int len = s.size();
	if (len == 1)return 1;
	int i = 0, j = 1;
	while (j<len)
		if (s[j] == s[i]){ i++; j++; }
		else j++;
		if (len % (j - i) == 0)return j - i;
		return len;
}

int main(){
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++){
		cin >> ws;
		getline(cin, s);
		stringstream ss(s);
		int mmax = 0;
		while (ss >> s){
			int fs = f(s);
			if (mmax < fs)mmax = fs;
		}
		if (i)cout << endl;
		cout << mmax << endl;
	}
}