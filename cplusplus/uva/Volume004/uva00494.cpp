/*******************************************************/
/* UVa 494 Kindergarten Counting Game                  */
/* Author: LanyiKnight [at] knightzone.org             */
/* Version: 2011/11/29                                 */
/*******************************************************/
#include<iostream>
#include<cstdio>
#include<cctype>
#include<string>
using namespace std;

int main(){
	string s, temp;
	int count;
	bool alphap = 0;
	while (getline(cin, s)){
		count = 0;
		for (int i = 0; i < s.length(); i++){
			if (isalpha(s[i]) && !alphap){
				alphap = 1;
				count++;
			}
			else if (!isalpha(s[i]) && alphap){
				alphap = 0;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}