#include <iostream>
#include <cctype>
using namespace std;

int main(){
	int st[2000],p=0;
	char ch;
	while (cin >> st[p++]){
		do{
			if (isdigit(cin.peek()))
				cin >> st[p++];
			cin.get(ch);
			if (ch == '+')st[--p - 1] += st[p]; 
			else if (ch == '-')st[--p - 1] -= st[p];
			else if (ch == '*')st[--p - 1] *= st[p];
			else if (ch == '/')st[--p - 1] /= st[p];
			else if (ch == '%')st[--p - 1] %= st[p];
		} while (ch != '\n');
		cout << st[--p] << endl;
	}
}