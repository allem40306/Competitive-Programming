#include <iostream>
#include <string>
using namespace std;
string s;
int lens;

void Knuth(string r,int lenr){
	if (lenr == lens){
		cout << r << endl;
	}
	else{
		for (int i = 0; i < lenr + 1; i++)
			Knuth(r.substr(0, i) + s[lenr] + r.substr(i, lenr - i), lenr + 1);
	}
	return;
}

int main(){
	int tn = 0;
	while (cin >> s){
		if (tn++)printf("\n");
		lens = s.size();
		Knuth("",0);
	}
}