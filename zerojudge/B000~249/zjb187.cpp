#include <iostream> 
int X(char a) {
	return a<='9'&&a>='0'?a-'0':a-'A'+10;
}int main(){
	char s[5];printf("十六進位表示法  相對應的十進位表示法\n");
	while(scanf("%s",&s)!=EOF){
		printf("      %s                 %d\n",s,X(s[0])*16+X(s[1]));
	}
}
