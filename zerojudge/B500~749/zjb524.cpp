#include <iostream>
#include <string>
using namespace std;
#define N 100000007

int main(){
	string s;
	while (cin >> s){
		int i = 0, t = 0, c = 0;
		int len = s.size();
		for (; i<len; i++)
			if (s[i] == 'y'){
			c += abs(3 * t - i);
			t++;
			}
		cout << c << endl;
	}
}