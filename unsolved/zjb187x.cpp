#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <iomanip>
using namespace std;

int stt(char a){
	if (isalpha(a))return 10 + int(a - 'A');
	return int(a - '0');
}

int main(){
	string ch;
	printf("�Q���i���ܪk  �۹������Q�i���ܪk\n");
	while (cin >> ch){
		cout <<setw(6)<< ch;
		cout<<setw(17)<<stt(ch[0]) * 16 + stt(ch[1]) << endl;;
	}
}