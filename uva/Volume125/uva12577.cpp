#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define max(x,y) x>y?x:y

int main(){
	string s;
	int cas = 1;
	while (cin >> s, s != "*"){
		if (s == "Hajj")printf("Case %d: Hajj-e-Akbar\n", cas++);
		else printf("Case %d: Hajj-e-Asghar\n", cas++);
	}
}