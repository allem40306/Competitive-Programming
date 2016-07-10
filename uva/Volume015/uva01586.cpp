#include<stdio.h>  
#include<string.h>  
char a[85];  
double M(char x)  
{  
    if(x=='C')  
        return (12.01);  
    else if(x=='H')  
        return (1.008);  
    else if(x=='O')  
        return (16.00);  
    else if(x=='N')  
        return (14.01);  
}  
int main()  
{  
    int T;  
    int n,i;  
    scanf("%d",&T);  
    while(T--)  
    {  
        double sum=0;  
        int i;  
        memset(a,0,sizeof(a));  
        scanf("%s",a);  
        n=strlen(a);  
        for(i=0; i<n; i++)  
        {  
            if((a[i+1]<'0')||(a[i+1]>'9'))  
            {  
                sum+=M(a[i]);  
            }  
            if((a[i+1]>='1')&&(a[i+1]<='9'))  
            {  
                if((a[i+2]>='1')&&(a[i+2]<='9'))  
                {  
                    sum+=M(a[i])*((a[i+1]-'0')*10+(a[i+2]-'0'));  
                    i+=2;  
                }  
                else  
                {  
                    sum+=M(a[i])*(a[i+1]-'0');  
                    i+=1;  
                }  
            }  
        }  
        printf("%.3lf\n",sum);  
    }  
    return 0;  
}  