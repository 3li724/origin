#include<stdio.h>

char a,b,goods[7];
int x,y,z,j,pr,sum,step=1;
int X[7],Y[7],s[7],num[7],buy[7];

int END(){
	if(a!='E') return 0;
	b=getchar(); if(b!='N') return 0;
	b=getchar();  return 1;
}

int end(){
	for(int i=1;i<=5;i++)
	  if(buy[i]<num[i])  return 0;
	return 1;
}

void init(){
	while(1){
		a=getchar();
		if(END()) return;
		if(a<65||a>90) continue;
		scanf("%d%d%d",&x,&y,&z);
		goods[x]=a; num[x]=z; s[x]=y;
	}
}

void select(){
	j=pr=sum=0;
	while(1){
		a=getchar();
		if(END()) break;
		if(a<65||a>90) continue;
		j++;  scanf("%d%d",&X[j],&Y[j]); //不能写成scanf("%d%d",&X[++j],&Y[j]);这样X,Y的值对应不起来 
		sum+=s[X[j]]*Y[j];
		if(buy[X[j]]+Y[j]>num[X[j]]) pr=1;
	}
}

void pay(){
	int k=0;
	for(int i=1;i<=j;i++) buy[X[i]]+=Y[i];
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
		switch(step){
			case 1:
				select();
				step=pr?2:3;
			break;
			case 2:
				step=1;
				printf("没货了,操作失败\n");	
			break;
			case 3:
				pay();
				step=1;
			break;
		}
		if(end()) break;
	}
	return 0;
}
/*
in：
A 3 7 5
B 2 3 5
B 1 3 3
END
A 3 1
B 2 1
END
1
5
5
B 1 3
B 2 2
A 3 3
END 
5
5
5
5
5
5
5
5
B 2 3
END
A 3 1
B 2 2
END
5
5
5

out:
1
4
没货了，操作失败 
2
*/
