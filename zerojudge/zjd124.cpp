#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;
int main() {
	string s;
	int sum;
	while (cin >> s){
		sum = 0;
		for (int i = 0; i<s.length(); i++){
			if (s[i] == '-'){      //處理負數
				continue;
			}
			else{
				sum = sum + (s[i] - '0');  //將字元的數字轉成數值
			}
		}
		if ((sum%3) == 0){
			cout << "yes" << endl;
		}
		else{
			cout << "no" << endl;
		}
	}
}