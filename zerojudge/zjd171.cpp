#include<iostream> 
#include<cmath>
using namespace std;

int main(){
	int m, n;
	while (cin >> n >> m){
		float ans = log10(n)*m;
		cout << (int)ans + 1 << endl;
	}
}