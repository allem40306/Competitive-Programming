#include <iostream>
#include <string>
using namespace std;

int sss(string s){
	int len = s.size(), a = 0;
	for (int i = 0; i < len; i++){
		a += int(s[i] - '0');
	}
	return a;
}

int iii(int a){
	int b = 0;
	while (a){ b += a % 10; a /= 10; }
	return b;
}

int main(){
	string s;
	while (cin >> s, s != "0"){
		int a = sss(s);
		while (a >= 10)a=iii(a);
		printf("%d\n", a);
	}
}