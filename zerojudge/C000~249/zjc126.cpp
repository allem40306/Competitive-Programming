#include<iostream>
#include<string>
using namespace std;

string po(string pr, string in){
	if (in.size() <= 1)return in;
	int left = in.find(pr[0]);
	return po(pr.substr(1, left), in.substr(0, left))
		+ po(pr.substr(left + 1), in.substr(left + 1))
		+ pr[0];
}

int main(){
	string pr, in;
	while (cin >> pr >> in){
		cout << po(pr, in) << endl;
	}
}
