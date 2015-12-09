#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int main(){
	int a, x, y, z, w, n, m;
	string s, wn;
	stringstream ss;
	cin >> a;
	while (a--){
		cin >> x >> y >> z >> w >> n >> m >> ws;
		getline(cin, s);
		stringstream ss(s);
		int p = 0; //p(oisoning) ¤¤¬r
		while (ss >> wn){
			if (p) m -= p*n;
			if (m <= 0) break;
			if (wn == "0")continue;
			else if (wn == "1")m += x;
			else if (wn == "2")m += y;
			else if (wn == "3")m -= z;
			else if (wn == "4"){ m -= w; p++; }
		}
		if (m <= 0)printf("bye~Rabbit\n");
		else printf("%dg\n", m);
	}
}