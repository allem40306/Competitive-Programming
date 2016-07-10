#include <iostream>
#include <string>
using namespace std;
#define N 50005
string s[N];

string its(int i){
	if (i == 0)return "0";
	string s;
	while (i){
		s = char('0' + (i % 10))+s;
		i /= 10;
	}
	return s;
}

void ans(){
	for (int i = 1; i < N; i++)s[i] = "-1";
	for (int i = 0; i <500; i++){
		for (int j = 0; j < 500; j++){
			for (int k = 0; k < 500; k++){
				int n = i*i + j*j + k*k;
				if (n>N - 5)break;
				if(s[n][0]=='-')s[n] = its(i) + ' ' + its(j) + ' ' + its(k);
			}
		}
	}
	return;
}

int main(){
	int t, n;
	cin >> t;
	ans();
	for (int i = 0; i < t; i++){
		cin >> n;
		cout << s[n] << endl;
	}
}