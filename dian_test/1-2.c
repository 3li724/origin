#include<stdio.h>
#include<windows.h>

int pr,x,num,sum;

int main(){
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
	FILE *fp=NULL;
	FILE *Fp=NULL;
	fp=fopen("1-2 in.txt","r");
	Fp=fopen("1-2 out.txt","w");
	if(fp==NULL){
		fprintf(Fp,"无法打开文件");
		fclose(fp);  fclose(Fp);
		return 0; 
	}
	fscanf(fp,"%d",&pr);
	while(1){
		fscanf(fp,"%d",&x);
		sum+=x;
		if(sum>=pr) {
			fprintf(Fp,"找零%d元",sum-pr);
			fclose(fp);  fclose(Fp);
			break;
		}
	}
	return 0;
}