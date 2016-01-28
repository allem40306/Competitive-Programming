#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int p[64][64], i, j, k;
	string a, b;
	for (i = 0; i < 64; i++){
		p[i][i] = 0;
		for (j = 0; j < i; j++)
			p[i][j] = p[j][i] = abs((i / 8 - j / 8)*(i % 8 - j % 8)) == 2 ? 1 : 64;
	}
	for (k = 0; k < 64; k++)
		for (i = 0; i < 64; i++)
			for (j = 0; j < 64; j++)
				p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
	while (cin >> a >> b){
		i = (a[0] - 'a') * 8 + a[1] - '1';
		j = (b[0] - 'a') * 8 + b[1] - '1';
		cout << "To get from "<<a<<" to "<<b<<" takes "<<p[i][j]<<" knight moves."<<endl;
	}
}

