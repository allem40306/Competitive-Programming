#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
#define N 5
int x, y, dx, dy, ok;

void move(char ch){
	if (ch == 'A')dx = x - 1, dy = y;
	else if (ch == 'B')dx = x + 1, dy = y;
	else if (ch == 'L')dx = x, dy = y - 1;
	else if (ch == 'R')dx = x, dy = y + 1;
	else ok = 0;
	return;
}

int main() {
	int ti = 0;
	string s[N];
	while (getline(cin, s[0])){
		if (s[0][0] == 'Z')break;
		if (s[0].size() < 5){
			if (s[0][4] == '\n')
				s[0] += ' ';
			else
				s[0] = ' ' + s[0];
		}
		for (int i = 1; i < N; i++){
			getline(cin, s[i]); 
			if (s[i].size() < 5)s[i] += ' ';
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (s[i][j] == ' ')x = i, y = j;
		string d, d1;
		while (1){
			cin >> d1;
			d += d1;
			if (d1[d1.size() - 1] == '0')break;
		}
		int lend = d.size();
		ok = 1;
		char ch;
		for (int i = 0; i < lend - 1; i++){
			move(d[i]);
			if (dx < 0 || dx >= N || dy < 0 || dy >= N){ ok = 0; break; }
			ch = s[x][y], s[x][y] = s[dx][dy], s[dx][dy] = ch;
			x = dx, y = dy;
		}
		if (ti++)cout << "\n";
		cout << "Puzzle #" << ti << ":\n";
		if (!ok)cout << "This puzzle has no final configuration.\n";
		else{
			for (int i = 0; i < N; i++){
				for (int j = 0; j < N; j++){
					cout << s[i][j];
					if (j < N - 1)cout << ' ';
				}
				cout << endl;
			}
		}
		cin >> ws;
	}

}