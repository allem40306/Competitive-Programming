#include <iostream>
using namespace std;

int main(){
	int n, m,count,total;
	while (cin >> n >> m){
		count = 0; total = 0;
		while (total <= m){
			count++;
			total += n;
			n++;
		}
		if (count == 0)count++;
		cout << count << endl;
	}
}
