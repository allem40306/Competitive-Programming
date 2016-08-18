#include <iostream>
#include <string>
using namespace std;
string s;

int two(int n){
	int m = 1;
	for (int i = 0; i < n; i++)m *= 2;
	return m;
}

int main(){
	int n;
	while (cin >> n){
		int stop = two(n);
		for (int i = 0; i < stop; i++){
			int ii = i;
			s = "";
			while (ii){
				char ch = ('0' + (ii % 2));
				s = ch+s; 
				ii /= 2;
		}
			int lens = s.size();
			for (int i = 0; i < n - lens; i++)printf("0");
			cout << s << endl;
		}
	}
}