#include <stdio.h>

char a,b;
int x,y,s,t,w,ex,num;

int main(){
	scanf("%c%d%d%d",&a,&ex,&w,&num); 
	b=getchar();  //第一个回车
	printf("请依次输入要买的货物,通道编号以及个数\n"); 
	while(b=getchar()){
		if(b<65||b>90) continue;  //防止以后读到回车
		scanf("%d%d",&x,&y); 
		if(num==0) break;
		if(b!=a||x!=ex) { printf("没货了\n");  continue; }
		if(y>num) {  printf("货不够了\n");  continue; }
		printf("请投币\n");
		while(1){
			scanf("%d",&s);  t+=s;
			if(t>=y*w) {  printf("找零%d元\n",t-y*w); break;}
			printf("请继续投币\n");
		}
		t=0; num-=y;
		printf("请依次输入要买的货物,通道编号以及个数\n"); 
	}
	return 0;
}
