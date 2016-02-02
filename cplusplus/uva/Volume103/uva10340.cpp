#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	string a, b;
	while (cin >> a >> b){
		int len = a.size();
		int lenn = b.size();
		int i = 0, j = 0;
		for (; i < len&&j < lenn;j++){
			if (a[i] == b[j])i++;
		}
		if (len == i)cout << "Yes\n";
		else cout << "No\n";
	}
}