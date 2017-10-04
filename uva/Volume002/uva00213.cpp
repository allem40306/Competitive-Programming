#include <stdio.h>
#include <string.h>

char readchar(){
	while(1){
		int ch=getchar();
		if(ch!='\n'&&ch!='\r')return ch;
	}
}

int readint(int len){
	int v=0;
	while(len--)v=v*2+(readchar()-'0');
	return v;
}

int code[8][(1<<8)];

int readcode(){//must use int
	memset(code,0,sizeof(code));
	code[1][0]=readchar();
	for(int len=2;len<=7;len++){
		for(int j=0;j<(1<<len)-1;j++){
			int ch=getchar();
			if(ch==EOF)return 0;
			if(ch=='\n'||ch=='\r')return 1;
			code[len][j]=ch;
		}
	}
}

void printcodes() {
  for(int len = 1; len <= 3; len++)
    for(int i = 0; i < (1<<len)-1; i++) {
      if(code[len][i] == 0) return;
      printf("code[%d][%d] = %c\n", len, i, code[len][i]);
    }
}


int main(){
	while(readcode()){
//		printcodes();
		while(1){
			int len=readint(3);
//			printf("len=%d\n",len);
			if(!len)break;
			while(1){
				int v=readint(len);
				if(v==(1<<len)-1)break;
//				printf("v=%d\n",v);
				putchar(code[len][v]);
			}
		}
		putchar('\n');
	}
} 
