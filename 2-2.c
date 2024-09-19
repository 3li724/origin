#include<stdio.h>
#define N 100005

struct in {
	char goods;
	int id,x,y,z;
}stack[N];

char a,b,goods[7];
int u,v,w,j,k,p,W,step=1;
int s[7],num[7],buy[7],ans[N],sum[N];

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
		if(END()) {
			step=2; p++;
			stack[++k].id=1;
			return;
		}
		if(a=='b') {
			k--;
			if(k<0) {k=0; printf("²Ù×÷Ê§°Ü\n"); return;}
			goods[stack[k+1].x]=0;
			num[stack[k+1].x]=s[stack[k+1].x]=0;
		}
		if(a<65||a>90) continue;
		scanf("%d%d%d",&u,&v,&w);
		stack[++k].id=1;  stack[k].goods=a;
		stack[k].x=u; stack[k].y=w; stack[k].z=v; num[u]=w; s[u]=v;
		break;
	}
}

void select(){
	while(1){
		a=getchar();
		if(END()){
			W=0; step=3;
			stack[++k].id=2;
			return;
		}
		if(a=='b') {
			step=stack[k].id;
			if(step==1) p--;
			if(step==2) 
				buy[stack[k].x]-=stack[k].y,
				sum[p]-=s[stack[k].x]*stack[k].y;
			if(step==3) W-=stack[k].z;
			k--;  return;
		}
		if(a<65||a>90) continue;
		scanf("%d%d",&u,&v);
		if(stack[k].id==3&&sum[p]) p+=1;
		stack[++k].id=2; stack[k].goods=a;
		stack[k].x=u; stack[k].y=v;
		sum[p]+=s[u]*v; buy[u]+=v;
		break;
	}
}

void pay(){
	while(1){
		a=getchar();
		if(a=='b') {
			step=stack[k].id;
			if(step==3) W-=stack[k].z;
			k--;  return;
		}
		if(a=='1'||a=='2'||a=='5'){
			W+=a-48;
			if(W>=sum[p]){
				step=2;
				ans[p]=W-sum[p];
				if(end()) step=4; 
			}
			stack[++k].z=a-48; stack[k].id=3;
			return;
		}
	}
}

int main(){
	while(1){
		switch(step){
			case 1:
				init();
			break;
			case 2:
				select();
			break;
			case 3:
				pay();
			break;
		}
		if(step==4) break; 
	}
	for(int i=1;i<=p;i++) printf("%d\n",ans[i]);
	return 0;
}
/*
in£º
A 3 7 5
B 2 3 5
END
back
B 1 3 3
END
A 3 2
B 2 2
back
back
A 3 1
B 2 1
END
1
2
back
back
1
5 
5
A 3 3
END
back
back
A 3 4
END
5
5
5
5
5
5
B 1 3
END
5
back
back
B 2 1
END 
5
5
5
back
1
2
B 2 3
END
5
5


out:
1
2
1
1
*/
