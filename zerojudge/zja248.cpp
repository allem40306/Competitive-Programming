#include<iostream> 
//案计ぃ跑 计搭
//计狡 
using namespace std;

int main(){
	int a,b,n,r;
	while (cin >> a >> b >> n){
		cout << a / b<<".";
		r = a%b;
		for (int i = 0; i < n; i++){
			r *= 10;
			cout << r / b;
			r%=b;
		}
		cout << endl;
	}
}
