#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	for (int i = 0; i < 9; i++){
		cin >> s;
		int t = 0;
		for (int j = 0; j < 9; j++)
			t += int(s[j] - '0');
		printf("%d\n", 45 - t);
	}
}