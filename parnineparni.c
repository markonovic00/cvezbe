#include <stdio.h>
#define MAX_SIZE 25

int main(){
	
	int x[MAX_SIZE]={0};
	int a[MAX_SIZE];
	int b[MAX_SIZE];
	int i,n,ai,bi;
	
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d",&n);
	}while(n<=0 || n>MAX_SIZE);
	
	for(i=0; i<n; i++){
		printf("\nClan niza[%d]: ",i);
		scanf("%d",&x[i]);
	}
	ai=0;
	bi=0;
	for(i=0;i<n;i++){
		if(x[i]%2==0){
			a[ai]=x[i];
			ai++;
		}
		else if(x[i]%2==1){
			b[bi]=x[i];
			bi++;
		}
	}
	printf("\n%d %d NIZ X=[",ai,bi);
	for(i=0;i<n;i++){
		printf("%d,",x[i]);
	}
	printf("]\n");
	
	for(i=0;i<ai;i++)
	{
		printf("parni:[%d]\n",a[i]);
	}
	
	for(i=0;i<bi;i++)
	{
		printf("neparni:[%d]\n",b[i]);
	}
	
	return 0;
}
