#include <iostream>
#include <string>
using namespace std;

int main() {
	string s,s2; char c1, c2;
	int n, ni = 0; cin >>n;
	for (; ni<n; ni++){
		cin >> ws;
		getline(cin, s); s2="";
		int lens = s.size(), i = 0;
		cin >> c1 >> c2;
		for (; s[i] != c1&&s[i]!=c2; i++)cout << s[i];
		cout << s[i];i++;
		for (; s[i] != c1&&s[i] != c2; i++)s2+=s[i];
		cout<<s[i];i++;
		for (; i<lens; i++)cout << s[i];
		cout<<"\n"<<s2<<"\n";
	}
}
