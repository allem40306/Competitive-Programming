#include <iostream>
using namespace std;

int main(){
	char ch;
	int n = 1;
	while (cin.get(ch)){
		if (ch == '"')
			if (n++ % 2)
				cout << "``";
			else cout << "''";
		else cout << ch;
	}
}
