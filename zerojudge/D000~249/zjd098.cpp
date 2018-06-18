#include <iostream>
#include <sstream>
using namespace std;
int main() {
	string s, w;
	int i, t, n;
	while (getline(cin, s)){
		stringstream ss(s);
		t = 0;
		while (ss >> w){
			n = 0;
			for (i = 0; i != w.size(); i++){
				if (!isdigit(w[i]))break;
				n = n * 10 + w[i] - '0';
			}
			if (i == w.size())
				t += n;
			}
		cout << t << endl;
	}
}