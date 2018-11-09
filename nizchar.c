#include<stdio.h>
#include<ctype.h>
#define MAX_SIZE 80

int main(){
	
	int i,n,bra;
	char c[MAX_SIZE];
	char a[MAX_SIZE]={0};
	
	do{
		printf("Unesite granicu niza: ");
		scanf("%d",&n);
	}while(n<=0 || n>MAX_SIZE);
	
	for(i=0;i<n;i++){
		printf("clan[%d]: ",i);
		scanf(" %c",&c[i]);
	}
	
	bra=0;
	for(i=0;i<n;i++){
		if(isalpha(c[i])!=0)
		{
			a[bra]=c[i];
			bra++;
		}	
	}
	
	printf("%s \n",a);
	
	return 0;
}
