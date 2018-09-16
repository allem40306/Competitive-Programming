#include <iostream>
#include <string>
#include <sstream>
using namespace std;
const int P = 52;
int res, xp, xa, yp, ya;

void parser(string s, int &point, int &a) {
	if (s == "A") {
		point = 11;
		a++;
		return;
	}
	if (s.size() == 2 || isalpha(s[0])) {
		point = 10;
		return;
	}
	point = (s[0] - '0');
	return;
}

int pp[P], aa[P];
void dfs(int index, int xp, int xa, int yp, int ya) {
	// cout << xp << ' ' << yp << '\n';
	if (yp > 21 && !ya)return;
	if (yp > 21 && ya) {
		yp -= 10;
		ya -= 1;
	}
	dfs(index + 1, xp, xa, yp + pp[index], ya + aa[index]);
	while (xp < 17) {
		xp += pp[index];
		xa += aa[index];
		if (xp + pp[index] > 21 && !(xa + aa[index]))break;
		if (xp + pp[index] > 21 && xa) {
			xp -= 10;
			xa--;
		}
		index++;
		// cout << xp << '-' << yp << '\n';
	}
	// cout << xp << ' ' << yp << '\n';
	if (xp == yp)res = max(res, 1);
	if (xp > 21 || xp < yp)res = max(res, 2);
	return;
}

int main() {
	int n;
	cin >> n;
	string s;
	while (n--) {
		for (int i = 0; i < P ; i++) {
			cin >> s;
			parser(s, pp[i], aa[i]);
		}
		res = 0;
		xp = pp[0] + pp[1];
		xa = aa[0] + aa[1];
		yp = pp[2] + pp[3];
		ya = aa[2] + aa[3];
		dfs(4, xp, xa, yp, xa);
		if (res == 0) {
			cout << "lose\n";
		} else if (res == 1) {
			cout << "push\n";
		} else {
			cout << "win\n";
		}
	}
}
