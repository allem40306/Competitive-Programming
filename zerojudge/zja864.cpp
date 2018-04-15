#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;
float f[7] = { 1.5, 1.0, 0.5, 0.25, 0, -0.25, -3.5 };
char c[7] = { 'M', 'K', 'G', 'F', 'A', 'B', 'O' };

void ch(float ff){
	int i = 0;
	for (i = 0; ff < f[i]; i++);
	cout << c[i] << endl;;
	return ;
}

int main(){
	string s;
	float mb, mv;
	while (cin >> s, s != "END"){
		cin >> mb >> mv;
		cout << s << ' ';
		cout <<fixed<<setprecision(2)<< mb - mv << ' ';
		ch(mb - mv);
	}
}