#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	while (cin >> s){
		int lens = s.size();
		for (int i = 0; i < lens; i++,printf("\n"))
			for (int j = 0; j < lens; j++)
				cout << s[(i + j) % lens];
	}
}