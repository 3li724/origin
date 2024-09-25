#include<stdio.h>
char a;
int x,y,z;

int main(){
	scanf("%c%d%d%d",&a,&x,&y,&z);
	printf("%d: ",x);
	for(int j=1;j<=z;j++) printf("%c",a);
	printf(" %d\n",y);
	return 0;
}
/*
A 3 7 5

3: AAAAA 7

*/