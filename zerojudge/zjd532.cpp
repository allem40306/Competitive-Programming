#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int cal(int a, int b, char ch){
	if (ch == '+')return a + b;
	if (ch == '-')return a - b;
	if (ch == '*')return a * b;
	if (ch == '/')return a / b;
	return a % b;
}

int main() {
	string s;
	char ch;
	int n, ni = 0;
	for (cin >> n; ni < n; ni++){
		cin >> s;
		int a = 0, b = 0, lens = s.size(), i = 0;
		for (; i < lens; i++){
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%'){
				ch = s[i]; i++; break;
			}
			else if (isdigit(s[i]))a = a * 10 + (s[i] - '0');
		}
		for (; i < lens; i++)
			if (isdigit(s[i]))b = b * 10 + (s[i] - '0');
		printf("%d\n", cal(a, b, ch));
	}
}