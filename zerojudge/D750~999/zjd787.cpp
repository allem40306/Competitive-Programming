#include <iostream>
#include <string>
using namespace std;
int dc = 0;

void diget(string a, string b){
	int d = 0;
	int la = a.size() - 1, lb = b.size() - 1;
	if (la > lb)for (int i = lb; i < la; i++)b = '0' + b;
	else if (la < lb)for (int i = la; i < lb; i++)a = '0' + a;
	int ab = (la > lb ? la : lb);
		while (ab>=0){
		int na = (a[ab] - '0'), nb = (b[ab] - '0');
		if ((na+nb + d) / 10){
			dc++;
			d = ((na+nb+ d) / 10);
		}
		else d = 0;
		ab--;
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