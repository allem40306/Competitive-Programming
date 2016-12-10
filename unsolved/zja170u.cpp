#include <iostream>
#include <string>
using namespace std;

int ett(string s){
	int ans = 0, i = s.size();
	for (int j = 0; j<i; j++)
		ans = ans * 8 +int (s[j] - '0');
	return ans;
}

string tts(int a){
	string s; int b;
	while (a){
		b = a % 16; a /= 16;
		s = (b>9 ? char('A' + b - 10) : char('0' + b)) + s;
	}
	return s;
}

int main(){
	int n, ni = 0;
	string s, r;
	for (scanf("%d", &n); ni<n; ni++){
		cin >> s >> r;
		cout << tts(ett(s) + ett(r)) << endl;
	}
}
