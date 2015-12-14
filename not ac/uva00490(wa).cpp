#include <iostream>
#include <string>
using namespace std;
#define N 102

int main(){
	string s, a[N];
	int mmax = 0, l = 0;
	while (getline(cin, s)){
		a[l] = s;
		if (mmax < a[l].size())mmax = a[l].size();
		l++;
	}
	if (mmax < a[l - 1].size())mmax = a[l - 1].size();
	for (int i = 0; i < mmax; i++){
		for (int j = l - 1; j >= 0; j--){
			int len = a[j].size();
			if (len <= i - 1)cout << ' ';
			else cout << a[j][i];
		}
		cout << endl;
	}
}