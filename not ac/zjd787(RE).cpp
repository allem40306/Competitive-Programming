#include <iostream>
#include <string>
using namespace std;
int dc = 0;

void diget(string a, string b){
	int d = 0;
	int la = a.size() - 1, lb = b.size() - 1;
	while (la + 1 || lb + 1){
		if ((int(a[la] - '0') + int(b[lb] - '0') + d) / 10){
			dc++;
			d = (int(a[la] - '0') + int(b[lb] - '0') + d) / 10;
		}
		else d = 0;
		la--; lb--;
	}
}

 int main(){
	 int n;
	 string a, b;
	 cin >> n;
	 while (n--){
		 dc = 0;
		 cin >> a >> b;
		 diget(a, b);
		 cout << dc << endl;
	 }
}