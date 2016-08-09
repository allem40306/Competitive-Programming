#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define N 10005
int sr, j;
string a[N], b[N];

struct str{
	string a;
	bool wr, ac;
}s[N];

void init(){
	for (int i = 0; i < N; i++)
		s[i].wr = s[i].ac = false;
	return;
}

int strech(){
	for (int i = 0; i < sr; i++)
		if (s[i].a == a[j])return i;
	s[sr++].a = a[j];
	return sr - 1;
}

int main(){
	int n, x = 0, y = 0;
	sr = 0;
	init();
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	for (j = n-1; j >= 0; j--){
		int len = strech();
			if (b[j] == "AC"){
				if (s[len].ac)continue;
				s[len].ac = true; x++;
				if (!s[len].wr)y++;
			}
			else{ s[len].wr = true; }
	}	
	printf("%d%s\n", y * 100 / x, "%");
}