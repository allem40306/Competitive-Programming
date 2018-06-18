#include <iostream>
#include <string>
#include <cctype>
using namespace std;
#define N 20000000
int ox[N], p[N], pr, ans[N];

void PrimeTable(){
	ox[0] = ox[1] = 1;
	pr = 0;
	for (int i = 2; i < N; i++){
		if (!ox[i]) p[pr++] = i;
		for (int j = 0; i*p[j]<N&&j < pr; j++)
			ox[i*p[j]] = 1;
	}
	ox[1] = 0;
}


int main(){
	PrimeTable();
	string s; 
	while (cin >> s){
		int sum, i, len;
		for (sum = 0, i = 0, len = s.size(); i < len; i++)
			if(isupper(s[i]))sum += int(s[i] - 'A') + 27;
			else sum += int(s[i] - 'a')+1;
		if (ox[sum])cout << "It is not a prime word.\n";
		else cout << "It is a prime word.\n";
	}
}