#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string sta(string s,string t){
	string r = "";
	for (int i = 0; i < 5; i++)
		r += (s[i] == '1'&&t[i] == '1' ? '1' : '0');
	return r;
}

string sto(string s, string t){
	string r = "";
	for (int i = 0; i < 5; i++)
		r += (s[i] == '1'||t[i] == '1' ? '1' : '0');
	return r;
}

int main() {
	string s;
	while (getline(cin, s)){
		stringstream ss(s);
		string w, ans;
		ss >> ans; cout << ans;
		while (ss >> w){
			if (w == "or"){
				printf("||");
				ss >> w; cout << w;
				ans=sto(ans, w);
			}
			else {
				printf("&&");
				ss >> w; cout << w;
				ans=sta(ans, w);
			}
		}
		printf(" = ");
		cout << ans << endl;
	}
}