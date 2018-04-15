#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;
#define N 100
#define D 8
int dx[D] = { -1, 0, 1, -1, 1, -1, 0, 1, }, dy[D] = { -1, -1, -1, 0, 0, 1, 1, 1, };
string s[15];

void x(int a, int b){
	int ans = 0;
	for(int i = 0; i < 8; i++){
		int kx = a + dx[i], ky = b + dy[i];
		if (0 <= kx && kx < 15 && 0 <= ky && ky < 30)
			if (s[kx][ky] == '*')ans++;
	}
	if (ans)cout << ans;
	else cout << '.';
	return;
}

int main(){
	string  a;
	while (cin >> a){
		s[0] = a;
		for (int i = 1; i < 15; i++)cin >> s[i];
		for (int j = 0; j < 15; j++){
			for (int k = 0; k < 30; k++){
				if (s[j][k] == '*')cout << '*';
				else x(j, k);
			}
			 cout << endl;
			}
	}
}