#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	int n, m, i = 0;
	for (cin >> n; i < n; i++){
		string s, r;
		cin >> s >> m;
		int lens = s.size(), lenr = 0, f = -1, cm = -1, mu = 0;
		for (int j = 0; j < lens; j++){
			if (isalnum(s[j])){
				if (f == -1 && s[j] != '0')f = j-mu;
				lenr++;
				r += s[j];
			}
			else{
				if (cm == -1 && s[j] == '.')cm = j-mu-1;
				mu++;
			}
		}
		if (cm!=-1&&f > cm){
			cm -= f;
			cout << r[f]; m--; f++;
			if (m)cout << '.';
			for (; m > 1; m--, f++)
				cout << r[f];
			if (m&&f + 1<lenr)cout << int(r[f] - '0' + (r[f + 1] >= '5'));
			printf("x10(%d)\n", cm);
		}
		else{
			cout << r[f]; m--; f++;
			if (m)cout << '.';
			for (; m > 1; m--, f++)
				cout << r[f];
			if (m&&f + 1<lenr)cout << int(r[f] - '0' + (r[f + 1] >= '5'));
			printf("x10(%d)\n", cm == -1 ? lenr-1 : cm);
		}
	}
}