#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;
#define chi(ch) int(ch-'A')
#define mp make_pair


int main(){
	long long n;
	while (cin >> n,n>=0){
		cout << n*(n + 1) / 2 + 1 << endl;
	}
}