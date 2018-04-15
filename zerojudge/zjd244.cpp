#include <iostream>
#include <map>
using namespace std;

int main(){
	map <int, int>::iterator it;
	map <int, int> stone;
	int n;
	while (cin >> n)stone[n]++;
	for (it = stone.begin(); it != stone.end(); it++)
		if (it->second % 3){ cout << it->first; break; }
}