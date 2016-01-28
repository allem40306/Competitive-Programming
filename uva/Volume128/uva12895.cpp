#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


string stn(int n){
	string s = "";
	while (n){
		s = char(n%10+48) + s;
		n /= 10;
	}
	return s;
}

int main(){
	int x,n, ta = 0;
	cin >> x;
	while (x--){
		cin >> n;
		string s = stn(n);
		int len = s.size();
		int t = 0;
		for (int i = 0; i < len; i++){
			int j = int(s[i] - '0');
			t += pow(j, len);
		}
		if (t == n)cout << "Armstrong\n";
		else cout << "Not Armstrong\n";
	}
}