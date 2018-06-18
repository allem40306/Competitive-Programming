#include <iostream>
using namespace std;
int main(){
	int a[10], h, c = 0, i;
	for (i = 0; i < 10; i++)                        //將蘋果高度輸入陣列
		cin >> a[i];
	cin >> h;                                   //輸入陶陶高度
	for (i = 0; i < 10; i++)                        //計算採得到幾顆蘋果
		c += (a[i] <= h + 30);                  //c(ount)--計數
	cout << c << endl;
}