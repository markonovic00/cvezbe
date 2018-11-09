#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 30

int main(){
	
	int i,n,trazeni;
	int brpog=0;
	int niz[MAX_SIZE];
	
	do{
		printf("Unesite velicinu niza max [%d]\n",MAX_SIZE);
		scanf("%d",&n);
	
	}while(n<=0 || n>=MAX_SIZE);
	
	for(i=0; i<MAX_SIZE; i++)
	{
		niz[i]=0;	
	}
	
	for(i=0; i<n;i++)
	{
		printf("Unesite clan niza [%d]: \n",i);
		scanf("%d",&niz[i]);
	}
	printf("Unesite trazeni broj: ");
	scanf("%d",&trazeni);
	
	for(i=0;i<n;i++)
	{
		if(niz[i]==trazeni){
			brpog++;
			}
	}
	printf("Broj %d se pojavljuje %d puta u nizu A=[",trazeni,brpog);
	
	for(i=0;i<n;i++)
	{
		if(i==n-1){
			printf("%d",niz[i]);
		}
		else{
		 printf("%d,",niz[i]);
		}
	}
	printf("] \n");
	
	return EXIT_SUCCESS;
}
