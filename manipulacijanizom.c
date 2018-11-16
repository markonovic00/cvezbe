#include <stdio.h>

#define MAX_SIZE 30

void unosNiza(int *,int *);
void ispis(int *,int);

int main(){

	int n,opcija;
	int niz[MAX_SIZE];
	
	do{
		printf("   Opcije: \n\n");
		printf("\t 1. Unos elemenata niza.\n");
		printf("\t 2. Izracunavanje sume.\n");
		printf("\t 3. Racunanje srednje vrednosti\n");
		printf("\t 4. Minimum.\n");
		printf("\t 5. Maximum.\n");
		printf("\t 6. Ispis Niza\n");
		printf("\t 7. Kraj.\n");
		scanf("%d",&opcija);	
	}while(opcija !=7);	
	
	
	switch(opcija){
		case 1: unosNiza(niz,&n); break;
		case 6: ispis(niz,n); break;
	}
}

void unosNiza(int *niz,int *n){
	
	int i;
	int vel; 
	printf("Unesite velicinu niza: \n");
	scanf("%d",&vel);
	for(i=0;i<vel;i++){
		
		printf("\nUnesite clan[%d]:",i);
		scanf("%d",&niz[i]);
	
	}
	*n=vel;
}

void ispis(int *niz,int n){
	
	int i;
	printf("[");
	for(i=0;i<n;i++){
		printf("%d",niz[i]);
		if(i<n-1){printf(",");}
	}
	printf("]\n");

}
