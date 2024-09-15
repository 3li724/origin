#include<stdio.h>

int x,y,z,j,pr,sum;
char a,goods[7];
int X[7],Y[7],s[7],num[7],buy[7];

int end(){
	for(int i=1;i<=5;i++)
	  if(buy[i]<num[i])  return 0;
	return 1;
}

void init(){
	while(1){
		a=getchar();
		if(a=='e') return;
		if(a<65||a>90) continue;
		scanf("%d%d%d",&x,&y,&z);
		goods[x]=a; num[x]=z; s[x]=y;
	}
}

void select(){
	j=pr=sum=0;
	while(1){
		a=getchar();
		if(a=='e') break;
		if(a<65||a>90) continue;
		j++;  scanf("%d%d",&X[j],&Y[j]); //不能写成scanf("%d%d",&X[++j],&Y[j]);这样X,Y的值对应不起来 
		sum+=s[X[j]]*Y[j];
		if(buy[X[j]]+Y[j]>num[X[j]]) pr=1;
	}
	if(pr) {
		printf("没货了,操作失败\n");
		return; 
	}
	for(int i=1;i<=j;i++) buy[X[i]]+=Y[i];
	return;
}

void pay(){
	int k=0;
	while(scanf("%d",&x)){
		k+=x;
		if(k>=sum) {
			printf("%d\n",k-sum);
			return;
		}
	}
}

int main(){
	init();
	while(1){
		select();
		if(!pr) pay();
		if(end()) break;
	}
	return 0;
}
/*
注：为操作方便，以'e'为一段输入结束的信号 
in：
A 3 7 5
B 2 3 5
B 1 3 3
e
A 3 1
B 2 1
e
1
5
5
B 1 3
B 2 2
A 3 3
e
5
5
5
5
5
5
5
5
B 2 3
e
A 3 1
B 2 2
e
5
5
5

out:
1
4
没货了，操作失败 
2
*/
