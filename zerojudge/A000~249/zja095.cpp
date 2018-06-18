#include <iostream>
using namespace std;
int main(){
	int a, b;
	while (cin >> a >> b){
		if(a!=b)cout << b + 1<<endl;
		else cout << b << endl;
	}
}
