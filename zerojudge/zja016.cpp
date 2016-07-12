#include <iostream>
using namespace std;

int main(){
	int num[9][9], found, sum;
	while (cin >> num[0][0]){
		for (int i = 1; i<9; i++){    //輸入數獨到num陣列 
			cin >> num[0][i];
		}
		for (int i = 1; i<9; i++){
			for (int j = 0; j<9; j++){
				cin >> num[i][j];
			}
		}
		found = 0;
		for (int i = 0; i<9; i++){     //判斷橫向是否符合數獨 
			sum = 0;
			for (int j = 0; j<9; j++){
				sum += num[i][j];
			}
			if (sum != 45){
				found = 1;
				break;
			}
		}
		for (int i = 0; i<9; i++){      //判斷直向是否符合數獨 
			sum = 0;
			for (int j = 0; j<9; j++){
				sum += num[j][i];
			}
			if (sum != 45){
				found = 1;
				break;
			}
		}
		for (int k = 0; k<9; k = k + 3){     //判斷第一列到第三列的三個九宮格是否符合數獨 
			sum = 0;
			for (int i = k; i<k + 3; i++){
				for (int j = 0; j<3; j++){
					sum += num[i][j];
				}
			}
			if (sum != 45){
				found = 1;
				break;
			}
		}
		for (int k = 0; k<9; k = k + 3){    //判斷第四列到第六列的三個九宮格是否符合數獨 
			sum = 0;
			for (int i = k; i<k + 3; i++){
				for (int j = 3; j<6; j++){
					sum += num[i][j];
				}
			}
			if (sum != 45){
				found = 1;
				break;
			}
		}
		for (int k = 0; k<9; k = k + 3){     //判斷第七列到第九列的三個九宮格是否符合數獨 
			sum = 0;
			for (int i = k; i<k + 3; i++){
				for (int j = 6; j<9; j++){
					sum += num[i][j];
				}
			}
			if (sum != 45){
				found = 1;
				break;
			}
		}
		if (found == 1){
			cout << "no" << endl;
		}
		else{
			cout << "yes" << endl;
		}
	}
	//system("pause"); 
}
