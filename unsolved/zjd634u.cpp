#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define N 100005
string s[N];

bool cmp(string a, string b){
	for (int i = 0; i < 10; i++)
		if (a[i] != b[i])
			return a[i] < b[i];
}

int main(){
	int n;
	cin >> n >> ws;
	for (int i = 0; i < n; i++){
		getline(cin, s[i]);
		while (s[i].size() < 10)s[i] += ' ';
	}
	sort(s, s + n, cmp);
	for (int i = 0; i < n; i++)
		cout << s[i] << endl;
}