#include<iostream>
#include <string>
#include <cstdlib>
using namespace std;

#define N 13

int int7[N] = { 1000, 900, 500, 400, 100,
90, 50, 40, 10, 9, 5, 4, 1 };
string str7[N] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };


string numToRom(int num)
{
	if (num == 0)
		return "ZERO";
	string s = "";
	for (int z = 0; z < N; z++){
		while (num >= int7[z]){
			num -= int7[z];
			s += str7[z];
		}
	}
	return s;
}

#define M 7

int qq[M] = { 1, 5, 10, 50, 100, 500, 1000 };
string rr = "IVXLCDM";

int f(char ch)
{
	for (int i = 0; i < M; i++)
		if (rr[i] == ch)
			return i;
	return -1;
}

int romToNum(string rom)
{
	int s = 0, last = -1;
	int res = 0;
	for (int i = rom.size() - 1; i >= 0; i--) {
		int tmp = f(rom[i]);
		if (tmp < last)
			res -= qq[tmp];
		else {
			res += qq[tmp];
			last = tmp;
		}
	}
	return res;
}


int main(){
	string a, b;
	while (cin >> a, a != "#")
	{
		cin >> b;
		cout << numToRom(abs(romToNum(a) - romToNum(b))) << endl;
	}
}