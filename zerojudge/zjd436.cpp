#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool comp(char a,char b){
	return a < b;
}


int main(){
	int n; 
	string s;
	cin >> n;
	while (n--){
		cin >> s;
		sort(s.begin(), s.end(), comp);
		do{
			cout << s << endl;
		} while (next_permutation(s.begin(), s.end(), comp));
		cout << endl;
	}
}
