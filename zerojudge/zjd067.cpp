#include <iostream>
using namespace std;
int main () {
	int y;
	cin >>  y;
	if(y%4==0&&y%100||y%400==0)cout<<"a leap year";
	else
	cout<<"a normal year";
}