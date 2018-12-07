#include <stdio.h>
#include <stdlib.h>

struct cvor_st{
    
    char znak;
    cvor_st *sledeci;
};

typedef struct cvor_st cvor;


cvor* dodajCvor(char c){
    cvor* novi = (cvor *) malloc(sizeof(cvor));
    novi->znak = c;
    novi->sledeci = NULL;
    return novi;
}

void dodajUListu(cvor **glava, char content){
    
    cvor *novi = dodajCvor(content);
    
    cvor *tekuci, *pret;
    
    if(*glava == NULL){
        *glava = novi;
        return;
    }
    
        tekuci = *glava;
        pret = *glava;
        while (tekuci != NULL){
            pret = tekuci;
            tekuci = tekuci -> sledeci;
        }
        pret -> sledeci = novi;
}

void stampaj(cvor** glava) {
  cvor *tekuci = *glava;
  while (tekuci != NULL) {
    printf(" %c", tekuci->znak);
    tekuci = tekuci->sledeci;
  }
}

void inicijalizuj(cvor** glava){
    *glava = NULL;
}

int main()
{
    cvor *glava;
    inicijalizuj(&glava);
    dodajUListu(&glava, 'a');
    stampaj(&glava);
    
    

    return 0; 
}
