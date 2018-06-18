#include<iostream> 
//偶數不變 奇數減一
//奇數重複一盆 
using namespace std;

int main(){
	int n;
	while (cin >> n)
			cout << n - (n%2) << endl;
}