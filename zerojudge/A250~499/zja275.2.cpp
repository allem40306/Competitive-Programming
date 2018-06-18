#include<stdio.h>
#include<string.h>
#define N 1000005 
// language c

int main(){
	static char a[N], b[N];
	int ascll[130];
	while (gets(a)){
		if (!strcmp(a, "STOP!!"))break;
		memset(ascll, 0, sizeof(ascll));
		gets(b);
		for (int i = 0; a[i]; i++){
			ascll[a[i]]++;
			ascll[b[i]]--;
		}
		int i = 33;
		for (i = 33; i <= 126; i++)
			if (ascll[i])break;
		printf("%s\n", i == 127 ? "yes" : "no");
	}
}