#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
	int t, ans, p;
	string s;
	cin >> t >> ws;
	while (t--){
		getline(cin, s);
		istringstream ss(s);
		ans = 0;
		while (ss >> p){
			ans += p;
		}
		printf("%d\n",ans);
	}
}