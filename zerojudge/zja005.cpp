#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, s[10],p;
	cin >> n; 
	while (n--){
		cin >> s[0] >> s[1] >> s[2] >> s[3];
		if (s[3] - s[2] == s[2] - s[1])
			cout << s[0]  << " "<< s[1] << " " << s[2] << " " << s[3] << " " << s[3] + (s[3] - s[2]) << endl;
		else
			cout << s[0] << " " << s[1] << " " << s[2] << " " << s[3] << " " << s[3] * (s[3] / s[2]) << endl;
	}
}
