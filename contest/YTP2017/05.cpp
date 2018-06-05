#include <iostream>
#include <string>

int d[100][100]; std::string s;

int doll(int l, int r) {
	int i, d, c = 0;
	for (d = 0, i = l; i <= r; i++)
		d *= 10, c += s[i]-'0', d += s[i]-'0';
	return (d%(c*2+1)+1)*(r-l+1);
}

int DFS2(int l, int r) {
	int i, m, n;
	if (l == r)
		return d[l][r] = s[l]-'0'+1;
	m = doll(l, r);
	for (i = l; i != r; i++)
		n = DFS2(l, i)+DFS2(i+1, r), m > n && (m = n);
	return d[l][r] = m;
}

int DFS(int l, int r) {
	if (d[l][r])
		return d[l][r];
	if (r-l+1 <= 6)
		return d[l][r] = DFS2(l, r);
 int i, m, n;
	for (m = 2147483647, i = l; i != r; i++)
		n = DFS(l, i)+DFS(i+1, r), m > n && (m = n);
	return d[l][r] = m;
}

int main() {
	int i, j;
	while (std::cin >> s) {
		for (i = 0; i <= s.size(); i++)
			for (j = 0; j <= s.size(); j++)
				d[i][j] = 0;
		DFS(0, s.size()-1), std::cout << d[0][s.size()-1] << '\n';
	}
}
