#include <iostream>
#include <map>
using namespace std;

int main(){
	map <int, int>::iterator it;
	map <int, int> stone;
	int n, m;
	cin >> n;
	while (n--){ 
		cin >> m;
		stone[m]++; }
	for (it = stone.begin(); it != stone.end(); it++)
		cout << it->first << " " << it->second << endl;
}