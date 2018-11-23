#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXIME 30
#define MAXEKIPA 20

typedef struct ekipa_st{
	char ime[MAXIME];
	unsigned bodovi;
	int razlika;
} EKIPA;

void ispis(EKIPA tabela[], int n);
void ucitaj(EKIPA tabela[], int *n);
void sortiraj(EKIPA tabela[], int n);

int main(int argc, char *argv[]){

	int n;
	
	return 0;
}

void ucitaj(EKIPA tabela[], int *n){
	
	int i;
	do{
		printf("Unesite broj ekipa:\n");
		scanf("%d",n);
	}while(*n<=0 || *n>MAXEKIPA);
	
	for(i=0; i<*n;i++){
	
		printf("Ekipa[%d]\n",i);
		scanf("%s %u %d",tabela[i].ime, &table[i].bodovi,&tabela[i].razlika); //Dalje bla bla bla
		
	}
	
}
