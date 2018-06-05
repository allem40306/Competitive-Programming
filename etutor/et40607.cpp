#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
void Selection_Sort(T *array, int num){
    for(int i=0;i<num;i++){
        int mn=i;
        for(int j=i;j<num;j++){
            if(array[j]<array[mn])mn=j;
        }
        T tmp=array[mn]; array[mn]=array[i]; array[i]=tmp;
    }
}

int main(){
    int n;
    string s;
    cin>>n>>s;
    if(s=="int"){
        int *a=(int*)malloc(n*sizeof(int));
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Selection_Sort(a,n);
        for(int i=0;i<n;i++){
            if(i)cout<<' ';
            cout<<a[i];
        }
        cout<<'\n';
    }else if(s=="double"){
        double *a=(double*)malloc(n*sizeof(double));
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Selection_Sort(a,n);
        for(int i=0;i<n;i++){
            if(i)cout<<' ';
            cout<<a[i];
        }
        cout<<'\n';
    }else if(s=="char"){
        char *a=(char*)malloc(n*sizeof(char));
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Selection_Sort(a,n);
        for(int i=0;i<n;i++){
            if(i)cout<<' ';
            cout<<a[i];
        }
        cout<<'\n';
    }else{
        string a[20];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Selection_Sort(a,n);
        for(int i=0;i<n;i++){
            if(i)cout<<' ';
            cout<<a[i];
        }
        cout<<'\n';
    }
}
