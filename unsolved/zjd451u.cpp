#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int n, m, i = 0;
	for (cin >> n; i < n; i++){
		string s, r;
		cin >> s >> m;
		int lens = s.size(), p = 0, pp = 0, mu = 0;
		for (int j = 0; j < lens; j++){
			if (s[j] == ','){ mu++; continue; }
			if (s[j] == '.'){
				if (p == 1){ pp = j; p = 2; }
				else if (p == 0)  p = -1;
				mu++;
			}
			else {
				if (p == 0 && s[j] != '0')
					p = 1;
				if (!pp&&s[j] != '0')pp = j - mu;
				r += s[j];
			}
		}
		int lenr = r.size();
		if (p == 1){
			int i = 1, mm = m - 1;
			cout << r[i - 1];
			if (mm)cout << '.';
			for (; mm > 1; i++, mm--)cout << r[i];
			if (mm&&i + 1 < lenr)cout << int(r[i] - '0' + (r[i + 1] >= '5'));
			printf("x10(%d)\n", lenr - 1);
		}
		else if (p == -1){
			int i = 1, mm = m - 1;
			cout << r[pp];
			if (mm)cout << '.';
			for (; mm>1; i++, mm--)cout << r[pp + i];
			if (mm&&i + 1 < lenr)cout << int(r[pp + i] - '0' + (r[pp + i + 1] >= '5'));
			printf("x10(%d)\n", -pp);
		}
		else {
			int i = 1, mm = m - 1;
			cout << r[0];
			if (mm)cout << '.';
			for (; mm>1; i++, mm--)cout << r[i];
			if (mm&&i + 1 < lenr)cout << int(r[i] - '0' + (r[i + 1] >= '5'));
			printf("x10(%d)\n", pp - 1);
		}
	}
}