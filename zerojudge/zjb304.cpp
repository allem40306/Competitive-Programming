#include<iostream>
#include<string>
using namespace std;

int main(){
	char st[128], p;
	string s;
	int n;
	cin >> n;
	getline(cin, s);
	while (n--){
		getline(cin, s); p = 0;
		for (int i = 0; i != s.size(); i++){
			if (s[i] == '(' || s[i] == '[')
				st[p++] = s[i];
			else if (s[i] == ')' &&st[p - 1] == '(' || s[i] == ']'&&st[p - 1] == '[')p--;
			else {
				if (s[i] == ')' || s[i] == ']')p++;
				break;
			}
		}
		if (p == '\0')
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}