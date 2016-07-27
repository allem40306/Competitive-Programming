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
			if (p!=1&&s[j] == '.')p = -1;
			else {
				if (p != 1&&s[j]!='0'){
					p = 1;
					if (!pp&&s[j]!='0')pp = j;
				}
				r += s[j];
			}
		}
		int lenr = r.size();
		if (p == 1){
			int i = 1; 
			cout << r[i - 1] << '.';
			for (; i < m - 1; i++)cout << r[i];
			if (i + 1 < lenr)cout << int(r[i]-'0' + (r[i + 1] >= '5'));
			printf("(%d)\n", lenr - 1);
		}
	}
}