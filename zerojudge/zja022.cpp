//a022 迴文

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){

	string i, ii;
	int a;
	while (cin >> i){
		a = i.size();
		if (a % 2)     //若字串長度為奇數
			i.erase(a / 2, 1); //將中間字元消除 ( 其實在這題中消掉中間字元沒多大意義 =="" )
		ii = i;
		reverse(i.begin(), i.end());         //將字串倒過來排

		if (i == ii)                   //如果倒過來後字串與原自串相同
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}

//reverse用法
//需#include <algorithm>
//設字串 a;
//reverse(從字串中第s個記憶體位置, 到字串中第d個記憶體位置)
//則 從 a[s] 至 a[d]會倒過來排