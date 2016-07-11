#include<cstdio>
#include<string.h>

int main(){
	char s1[1000001], s2[1000001];
	while (scanf_s("%s", s1), !strcmp(s1, "STOP!!")){
		scanf_s("%s", s2);
		int d[128] = {};
		for (int i = 0; s1[i]; i++){
			d[s1[i]]++; d[s2[i]]--;
		}
		int flag = 0;
		for (int j = 0; j < 128; j++)
			flag += (d[j] == 0);
		if (flag == 128) printf("%s", "yes\n");
		else printf("%S", "no\n");
	}
}