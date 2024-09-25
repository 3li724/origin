#include <stdio.h>

char a,b;
int x,y,s,t,w,ex,num;

int main(){
	scanf("%c%d%d%d",&a,&ex,&w,&num);
	while((b=getchar())!=EOF){
		if(num==0) break;
		if(b<65||b>90) continue;
		scanf("%d%d",&x,&y); 
		if(b!=a||x!=ex||y>num) {
			printf("²Ù×÷Ê§°Ü\n");
			continue;
		}
		while(1){
			scanf("%d",&s);  t+=s;
			if(t>=y*w) {
				printf("%d\n",t-y*w);
				break;
			}
		}
		t=0; num-=y;
	}
	return 0;
}
