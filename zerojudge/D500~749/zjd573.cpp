#include <cstdio>
#define N 100000
 
int main(){
	int n, o, np, p,arr[N];
	while (scanf("%d", &n) != EOF){
		for (int i = 0; i<n; i++){
			scanf("%d %d", &o, &np);
			for (int j = 0; j<np; j++){
				scanf("%d", &p);
				arr[p]=o;
			}
		}
		scanf("%d", &p); printf("%d\n",arr[p]);
	}
}
