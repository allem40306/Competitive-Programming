#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
	set <string> d;
	int n, m;
	string s;
	cin >> n;
	while (n--){
		cin >> s;
		d.insert(s);
	}
	cin >> m;
	while (m--){
		cin >> s;
		if (d.find(s) == d.end()){
			cout << "no\n";
			d.insert(s);
		}
		else cout << "yes\n";
	}
}