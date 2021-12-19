#include <iostream>
using namespace std;

int main(){  
    int n,o=0;  
    while(cin>>n){  
        if(o)cout<<'\n'; o=1;  
        if(n%2==0){  
            cout<<"It is not an odd number.\n";  
            continue;  
        }  
        int **a=new int*[n]; 
        for(int i=0;i<n;i++){
            a[i]=new int[n];
        }
        int xx=n-1,yy=n/2,nn=1;  
        for(int i=0;i<n;i++){  
            if(i){  
                xx=(xx-1+n)%n;  
            }  
            for(int j=0;j<n;j++){  
                if(j){  
                    xx=(xx+1)%n;  
                    yy=(yy+1)%n;  
                }  
                a[xx][yy]=nn++;  
            }  
        }  
        cout<<(1+n*n)*n/2<<'\n';  
        for(int i=0;i<n;i++){  
            for(int j=n-1;j>=0;j--){  
                if(j!=n-1)cout<<' ';
                cout<<a[j][i];
            }  
            cout<<'\n';  
        }  
        for(int i=0;i<n;i++){
            delete []a[i];
        }
        delete []a;  
    }  
}  