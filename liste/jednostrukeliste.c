#include<stdio.h>
#include<stdlib.h>

typedef struct cvor_st{
	
	char znak;
	cvor_st *sledeci;
	
} cvor;

cvor *dodaj_cvor(char c){
	cvor *novi=(cvor *)malloc(sizeof(cvor));
	novi->znak=c;
	novi->sledeci=NULL;
	return novi;
}

void dodaj_u_listu(cvor **glava, char content){

	cvor *novi= dodaj_cvor(content);
	
	cvor *tekuci, *pret;
	
	if(*glava==NULL){
		*glava=novi;
		return;
	}
	
	tekuci=*glava;
	pret=*glava;
	while(tekuci!=NULL){
		pret=tekuci;
		tekuci=tekuci->sledeci;
	}
	pret -> sledeci=novi;
}

void stampaj(cvor** glava) {
  cvor *tekuci = *glava;
  while (tekuci != NULL) {
    printf(" %c", tekuci->znak);
    tekuci = tekuci->sledeci;
  }
}

void inicijalizuj(cvor **glava){
	*glava=NULL;
}

int main(int argc, char *argv[]){
	
	covr *glava;
	inicijalizuj(&glava);
	dodaj_u_listu(&glava,'a');

	return 0;
}


