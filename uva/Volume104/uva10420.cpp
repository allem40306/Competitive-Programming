#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
#define N 2000

int main() {
	string s, r[N];
	int rr = 0, n, ni = 0;
	for (cin >> n>>ws; ni < n;ni++){
		getline(cin, s);
		stringstream ss(s);
		ss >> s;
		r[rr++] = s;
	}
	sort(r, r + rr);
	for (int t = 1, i = 0; i < rr; i++){
		if (i!=rr-1&&r[i] == r[i + 1])t++;
		else{
			cout << r[i] << ' ' << t << endl;
			t = 1;
		}
	}
}