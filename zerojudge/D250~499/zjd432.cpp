#include<iostream>
#include<string>
using namespace std;

string pr(string in , string po ){
	if (in.size() <= 1)return in ;
	int left = in.find(po[po.size()-1]);
	return po[po.size() - 1]
		+ pr(in.substr(0, left), po.substr(0, left))
		+ pr(in.substr(left + 1), po.substr(left, po.size() - 1 - left));
}

int main(){
	string in,po;
	while (cin >> in >> po){
		cout << pr(in,po) << endl;
	}
}