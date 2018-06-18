#include<iostream> 
using namespace std;

int main(){
	int a,b,n;
	while (cin >> n,n){
		for ( a = n; a ; a--){
			for (b = 1; b <= n; b++){
				cout <<( (b >= a) ? '+' : '_');
			}
			cout << endl;
		}
		cout << endl;
	}
}