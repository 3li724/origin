#include<stdio.h>

int pr,x,num,sum;

int main(){
	FILE *fp=NULL;
	FILE *Fp=NULL;
	fp=fopen("1-2 in.txt","r");
	Fp=fopen("1-2 out.txt","w");
	if(fp==NULL){
		fprintf(Fp,"�޷����ļ�");
		fclose(fp);  fclose(Fp);
		return 0; 
	}
	fscanf(fp,"%d",&pr);
	while(1){
		fscanf(fp,"%d",&x);
		sum+=x;
		if(sum>=pr) {
			fprintf(Fp,"����%dԪ",sum-pr);
			fclose(fp);  fclose(Fp);
			break;
		}
	}
	return 0;
}
/*
7
1
2
5

1
*/
