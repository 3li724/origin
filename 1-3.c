#include <stdio.h>

char a,b;
int x,y,s,t,w,ex,num;

int main(){
	scanf("%c%d%d%d",&a,&ex,&w,&num); 
	b=getchar();  //��һ���س�
	printf("����������Ҫ��Ļ���,ͨ������Լ�����\n"); 
	while(b=getchar()){
		if(b<65||b>90) continue;  //��ֹ�Ժ�����س�
		scanf("%d%d",&x,&y); 
		if(num==0) break;
		if(b!=a||x!=ex) { printf("û����\n");  continue; }
		if(y>num) {  printf("��������\n");  continue; }
		printf("��Ͷ��\n");
		while(1){
			scanf("%d",&s);  t+=s;
			if(t>=y*w) {  printf("����%dԪ\n",t-y*w); break;}
			printf("�����Ͷ��\n");
		}
		t=0; num-=y;
		printf("����������Ҫ��Ļ���,ͨ������Լ�����\n"); 
	}
	return 0;
}
