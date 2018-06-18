#include <iostream>
#include <cctype>
#include <string>
using namespace std;
#define N 26


int main() {
	double a[N];
	string s;
	while (getline(cin,s)) {
		for (int i = 0; i < N; i++)a[i] = 0;
		int lens = s.size(), ch = 0;
		for (int i = 0; i < lens; i++)
			if(isalpha(s[i]))ch++,a[toupper(s[i]) - 'A'] += 1.0;
		for (int i = 0; i < N; i++) {
			if (i)printf(" ");
			printf("%.0f", a[i]);
		}
		printf("\n");
		for (int i = 0; i < N; i++) {
			if (i)printf(" ");
			printf("%.2f", a[i] * 100.0 / ch);
		}
		printf("\n");
	}
}