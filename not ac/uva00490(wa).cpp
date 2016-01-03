#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define N 102


int main(){
	int len[N];
	string s, a[N];
	int mmax = 0, l = 0;
	while (getline(cin, s)){
		a[l] = s;
		len[l] = a[l].size();
		mmax = (len[l] > mmax ? len[l] : mmax);
		l++;
	}
	for (int i = 0; i < mmax; i++){
		for (int j = l - 1; j >= 0; j--){
			if (len[j] <= i - 1)cout << ' ';
			else cout << a[j][i];
		}
		cout << endl;
	}
}