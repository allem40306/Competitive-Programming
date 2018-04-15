#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
string s;

void uf(double f){
	while (f){
		f*=2;
		if(f>=1.0){
			s+='1';
			f-=1.0;
		}
		else
		s+='0';
	}
}

void un(int n){
	while (n){
		s = (n % 2 ? '1' : '0') + s;
		n /= 2;
	}
}

int main(){
	double f; int n;
	while (cin >> f){
		n = int(f / 1);
		f -= double(n);
		if (!n&&!f)printf("0");
		else if (!n){
			s = "0.";
			uf(f);
		}
		else if (!f){
			s = "";
			un(n);
		}
		else{
			s="";
			un(n);
			s += '.';
			uf(f);
		}
		cout << s << endl;
	}
}