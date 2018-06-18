#include <iostream>  
#include <cstdlib>  
#include <cstring>  
#include <cstdio>  
  
using namespace std;  
  
char year[100000];  
int  numb[100000];  
  
int cdiv( int m )  
{  
    int l = strlen(year)-1;  
    for ( int i = 0 ; i <= l ; ++ i )  
        numb[i] = year[i]-'0';  
    for ( int i = 0 ; i < l ; ++ i )   
        numb[i+1] += numb[i]%m*10;  
    return (numb[l]%m == 0);  
}  
  
int main()  
{  
    int flag,y=0;  
    while ( cin >> year ) {  
        flag = 0; 
		if(y++)printf("\n");
        if ( cdiv(400) || cdiv(4) && !cdiv(100) ) {  
            printf("This is leap year.\n");  
            flag += 1;  
        }  
        if ( cdiv(15) ) {  
            printf("This is huluculu festival year.\n");  
            flag += 2;  
        }  
        if ( flag%2 && cdiv(55) )  
            printf("This is bulukulu festival year.\n");  
        if ( !flag )  
            printf("This is an ordinary year.\n");     
    }  
    return 0;  
}
