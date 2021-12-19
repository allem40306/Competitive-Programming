#define N 1505
int lin[N];
void initialize(int n){
	for(int i=0;i<n;i++)
		lin[i]=i;
}
int hasEdge(int a, int b){
	int x=(a>b?a:b);
	lin[x]--;
	return 1-(lin[x]>0);
}
