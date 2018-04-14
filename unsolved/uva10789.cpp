#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define N 128
#define M 205
bool ox[M];
int p[M], pr = 0;

void primetable(){
	memset(ox, 0, sizeof(ox));
	ox[0] = ox[1] = 1;
	for (int i = 2; i < M; i++){
		if (!ox[i])p[pr++] = i;
		for (int j = 0; i*p[j] <= M&&j<pr; j++)
			ox[i*p[j]] = 1;
	}
}

int main() {
	int t, ti = 1, a[N];
	string s;
	primetable();
	for (cin >> t; ti <= t; ti++){
		memset(a, 0, sizeof(a));
		cin >> s;
		int lens = s.size();
		for (int i = 0; i < lens; i++)
			a[s[i]]++;
		bool f = 0;
		printf("Case %d: ", ti);
		for (int i = 0; i < N; i++)
			if (!ox[a[i]] && (f = 1))
				cout << char(i);
		printf(f ? "\n" : "empty\n");
	}
}
