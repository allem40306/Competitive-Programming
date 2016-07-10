#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <string>  
using namespace std;  
char s1[110],s2[110];  
int n1[210],n2[210];  
int main()  
{  
    int i,j;  
    while (~scanf("%s%s",s1,s2))  
    {  
        memset(n1,0,sizeof(n1));  
        memset(n2,0,sizeof(n2));  
        int len1=strlen(s1);  
        int len2=strlen(s2);  
        for (i=0;i<len1;i++)  n1[i]=s1[i]-'0';  
        for (i=0;i<len2;i++)  n2[i]=s2[i]-'0';  
        int minlen=max(len1,len2);  
        for (i=0;i<len1;i++)  
        {  
            for (j=0;j<len2;j++)  
            {  
                if (n1[i+j]+n2[j]>=4)  
                    break;  
            }  
            if (j==len2)  
                break;  
        }  
        int le1=len2+i;  
        for (i=0;i<len2;i++)  
        {  
            for (j=0;j<len1;j++)  
            {  
                if (n2[i+j]+n1[j]>=4)  
                    break;  
            }  
            if (j==len1)  
                break;  
        }  
        int le2=i+len1;  
        minlen=max(minlen,min(le1,le2));  
        printf("%d\n",minlen);  
    }  
    return 0;  
}  