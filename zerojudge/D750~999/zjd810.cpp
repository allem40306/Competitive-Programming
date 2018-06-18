#include <iostream>
using namespace std;
#define S 25 //stair 階梯
int s[4][S] = {};
void run() {
	s[1][0] = 1;s[1][1] = 1;s[1][2] = 1;
	s[2][0] = 1;s[2][1] = 1;s[2][2] = 2;
	s[3][0] = 1;s[3][1] = 1;s[3][2] = 2;
	for (int i= 3;i < S;i++) {
		s[1][i] = 1;
		s[2][i] = s[2][i - 1] + s[2][i - 2];
		s[3][i] = s[3][i - 1] + s[3][i - 2] + s[3][i - 3];
	}
}

int main() {
	run();
	int t, k;
	while (cin >> t >> k)
		cout << s[t][0 - k] << endl;
}