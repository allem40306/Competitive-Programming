#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main(){
	float v,r;
	while (cin >> v >> r){
		cout << fixed<< setprecision(4)<<v*1000 / r << endl;
	}
}