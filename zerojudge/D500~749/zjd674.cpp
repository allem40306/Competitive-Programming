#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	string m, f;
	int kas = 0;
	while (getline(cin, m), m != "#"){
		getline(cin, f);
		int i, j;
		int choose[102][102] = {};
		for (i = 0; i < m.size(); i++)
			for (j = 0; j < f.size(); j++){
			if (m[i] == f[j])choose[i + 1][j + 1] = choose[i][j] + 1;
			else choose[i + 1][j + 1] = max(choose[i][j + 1], choose[i + 1][j]);
			}
		cout << "Case #" << ++kas << ": you can visit at most " << choose[i][j] << " cities.\n";
	}
}
