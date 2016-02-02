#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

 int main(){
	 int t;
	 string s;
	 char a[2];
	 cin >> t;
	 while (t--){
		 cin >> ws;
		 getline(cin,s);
		 cin>>a[0] >> a[1];
		 if (s.find(a[0])<s.find(a[1])){
			 cout << s.substr(0, s.find(a[0]) + 1) << s.substr(s.find(a[1]), s.size() - s.find(a[1])+1) << endl;
			 cout << s.substr(s.find(a[0]) + 1, s.find(a[1]) - s.find(a[0]) - 1) << endl;
		 }
		 else{
			 cout << s.substr(0, s.find(a[1]) + 1) << s.substr(s.find(a[0]), s.size() - s.find(a[0]) + 1) << endl;
			 cout << s.substr(s.find(a[1]) + 1, s.find(a[0]) - s.find(a[1]) - 1) << endl;
		}
	 }
}