/*
假设输入到e时结束 
*/ 
#include<stdio.h>

int x,y,z;
char a,goods[7];
int s[7],num[7];

int main(){
	while(scanf("%c",&a)){
		if(a=='e'){
			for(int i=1;i<=5;i++)
				if (num[i]) {
					printf("%d: ",i);
					for(int j=1;j<=num[i];j++) printf("%c",goods[i]);
					printf(" %d\n",s[i]);
				}
			break;
		}
		if(a>=65&&a<=90){  //a可能读到回车 
			scanf("%d%d%d",&x,&y,&z);
			num[x]=z; s[x]=y; goods[x]=a;
		}
	}
	return 0;
}
/*

A 3 7 5

3: AAAAA 7

*/
