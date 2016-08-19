#include <iostream>
#include <map>
using namespace std;

int main(){
	int n,m;
	while (cin >> n){
		map <int, int> ma;
		
		for (int i = 0; i < n; i++){
			cin >> m;
			ma[m]++;
		}
		for (map<int, int>::iterator it =ma.begin(); it != ma.end(); it++)
			printf("%d %d\n", it->first, it->second);
	}
}