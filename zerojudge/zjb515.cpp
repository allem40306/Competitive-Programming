#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define N 30
string as[N] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

int main() {
	int n;
	cin >> n >> ws;
	while (n--){
		string s, r;
		getline(cin, s);
		stringstream ss(s);
		while (ss >> r){
			for (int i = 0; i < N; i++)
				if (r == as[i]){ cout << char('A' + i); break; }
		}
		printf("\n");
	}
}