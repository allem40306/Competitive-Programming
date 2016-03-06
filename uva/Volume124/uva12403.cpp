#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define max(x,y) x>y?x:y

int main(){
	string s;
	int t, m, n = 0;
	cin >> t;
	while (t--){
		cin >> s;
		if (s == "donate"){
			cin >> m;
			n += m;
		}
		else printf("%d\n", n);
	}
}