#include <iostream>
#include <string>
using namespace std;

int main(){
	int t, k = 0, d = 0, s = 0, ck = 0;
	string ss, r[7] = { "You have slain an enemie.", "KILLING SPREE!", "RAMPAGE~"
		, "UNSTOPPABLE!", "DOMINATING!", "GUALIKE!", "LEGENDARY!" };
	for (cin >> t; t; t--){
		cin >> ss;
		if (ss[0] == 'D' && (d+=1))
			cout << (ck<3? "You have been slained.\n" : "SHUTDOWN.\n"),ck=0;
		else if (ss[4] == 'K' && (ck+=1) && (k+=1))
			cout << (ck>2 ? (ck >= 8 ? r[6] : r[ck - 2]) : r[0]) << endl;
		else s++;
	}
	printf("%d/%d/%d", k, d, s);
}
