#include<stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

int main(){
	
	int niz[MAX_SIZE]={0};
	int n,i,r;
	int maxbr;
	do{
		printf("unesite niz ne veci od 20 \n");
		scanf("%d",&n);
	
	}while(n<=0 || n>MAX_SIZE);
	
	for(i=0; i<n;i++){
		printf("unesite clan niza[%d]:",i);
		scanf("%d",&niz[i]);
	}
	maxbr=niz[0];
	for(i=0; i<n;i++){
		if(niz[i]>maxbr){
			maxbr=niz[i];
		}
	}
	printf("\n");
	printf("MaxBr je %d \n",maxbr);
		
	
	return 0;
}
