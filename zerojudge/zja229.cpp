#include<iostream>					
#include<string>
#include<stdio.h>
using namespace std;

void ans(int a, int b, string s){
	if (a)
		ans(a - 1, b, s + "(");
	if (b && b>a)
		ans(a, b - 1, s + ")");
	if (a == 0 && b == 0){
		printf("%s\n", s.c_str());
		return;
	}
}

int main(){
	int n;
	while (cin >> n){
		ans(n, n, "");
	}
}
