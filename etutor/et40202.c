#include <stdio.h>
struct Union{
    char ch;
    short s;
    int i;
    long l;
}u;

int main(){
    scanf("%c %hd %d %ld",&u.ch,&u.s,&u.i,&u.l);
    printf("'%c' printed as a character is %c\n",u.ch,(char)(u.ch));
    printf("'%c' printed as a short integer is %hd\n",u.ch,(short)(u.ch));
    printf("'%c' printed as a integer is %d\n",u.ch,(int)(u.ch));
    printf("'%c' printed as a long integer is %ld\n",u.ch,(long)(u.ch));

    printf("%hd printed as a character is %c\n",u.s,(char)(u.s));
    printf("%hd printed as a short integer is %hd\n",u.s,(short)(u.s));
    printf("%hd printed as a integer is %d\n",u.s,(int)(u.s));
    printf("%hd printed as a long integer is %ld\n",u.s,(long)(u.s));

    printf("%d printed as a character is %c\n",u.i,(char)(u.i));
    printf("%d printed as a short integer is %hd\n",u.i,(short)(u.i));
    printf("%d printed as a integer is %d\n",u.i,(int)(u.i));
    printf("%d printed as a long integer is %ld\n",u.i,(long)(u.i));

    printf("%ld printed as a character is %c\n",u.l,(char)(u.l));
    printf("%ld printed as a short integer is %hd\n",u.l,(short)(u.l));
    printf("%ld printed as a integer is %d\n",u.l,(int)(u.l));
    printf("%ld printed as a long integer is %ld\n",u.l,(long)(u.l));
}
