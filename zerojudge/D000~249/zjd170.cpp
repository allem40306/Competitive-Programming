#include <cstdio>

int main(){
	int n,ni=0,x1,y1,x2,y2,x3,y3;
	for(scanf("%d",&n);ni<n;ni++){
		scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
		if(((y1-y2)*(x1-x3)==(x1-x2)*(y1-y3)&&((((y1<=y3)&&(y2>=y3))||((y1>=y3)&&(y2<=y3)))&&(((x1<=x3)&&(x2>=x3))||((x1>=x3)&&(x2<=x3)))))
        ||(x1==x2&&x2==x3&&(((y1<=y3)&&(y2>=y3))||((y1>=y3)&&(y2<=y3))))
        ||(y1==y2&&y2==y3&&(((x1<=x3)&&(x2>=x3))||((x1>=x3)&&(x2<=x3)))))
		printf("�Ӧ����F��!�����Q���ڦ��I\n");
		else printf("���ˤj�H!���ˤj�H!�ڧ֨�F�I\n");
	}
}
