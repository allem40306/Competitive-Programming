#include <iostream> 
int X(char a) {
	return a<='9'&&a>='0'?a-'0':a-'A'+10;
}int main(){
	char s[5];printf("�Q���i���ܪk  �۹������Q�i���ܪk\n");
	while(scanf("%s",&s)!=EOF){
		printf("      %s                 %d\n",s,X(s[0])*16+X(s[1]));
	}
}
