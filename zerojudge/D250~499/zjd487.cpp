#include <iostream>  
using namespace std;

void po(int a){
   int i;
   for(i=a;i;i--){
     if(i==1)cout<<"1 = ";
     else cout<<i<<" * ";
    }
}

int st(int b){
    int j,sum=1;
   for(j=b;j;j--){
     sum*=j;
    }
   return sum;
}
  
int main()  {  
   int n;
   while(cin>>n){
       cout<<n<<"! = ";
       if(n==0)cout<<"1 = 1\n";
       else{
          po(n);   
          cout<<st(n)<<endl;
       }
    }
}