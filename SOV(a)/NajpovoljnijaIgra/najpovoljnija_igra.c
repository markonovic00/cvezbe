#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct igra_st{

    char naziv_igre[11];
    char naziv_zanra[9];
    char naziv_platforme[9];
    double cena_igre;

    struct igra_st *next;

} IGRA;


void initialize(IGRA **head);
IGRA *novi_el(char *, char * ,char *, double);
void dodaj_u_listu(IGRA **head,char *, char * ,char *, double);
void ucitaj(FILE *,IGRA **);
void ispis(IGRA *);
FILE *safe_open(char *, char *, int);


int main(int argc, char *argv[])
{

    if (argc !=5){

        printf("Ocekivani ulaz je: ./povoljne_igre PC Sandbox igre.txt analiza.txt");
        exit(666);

    }

    IGRA *head;

    initialize(&head);

    FILE *in;
    FILE *out;

    in=safe_open(argv[3],"r",1);
    out=safe_open(argv[4],"w",2);

    ucitaj(in,&head);


    fclose(in);
    fclose(out);

    return 0;
}

FILE *safe_open(char *filename, char *mode, int close){

    FILE *fp=fopen(filename,mode);

    if (fp==NULL){
        printf("Nije moguce otovoriti %s",filename);
        exit(close);
    }

    return fp;
}

void initialize(IGRA **head){

    *head==NULL;

}

IGRA *novi_el(char *naziv_igre, char *naziv_platforme ,char *naziv_zanra, double cena_igre){

    IGRA *novi = malloc(sizeof(IGRA));

    if (novi==NULL){
        printf("Nije moguce zauzeti memoriju\n");
        exit(69);
    }

    strcpy(novi->naziv_igre,naziv_igre);
    strcpy(novi->naziv_platforme,naziv_platforme);
    strcpy(novi->naziv_zanra,naziv_zanra);
    novi->cena_igre=cena_igre;

    novi->next=NULL;

    return novi;

}

void dodaj_u_listu(IGRA **head,char *naziv_igre, char *naziv_platforme ,char *naziv_zanra, double cena_igre){

    IGRA *novi=novi_el(naziv_igre,naziv_platforme,naziv_zanra,cena_igre);

    if(*head==NULL){
        *head=novi;
        return;
    }

    dodaj_u_listu(&(*head)->next,naziv_igre,naziv_platforme,naziv_zanra,cena_igre);

}

void ucitaj(FILE *in,IGRA **head){

    char naziv_igre1[11];
    char naziv_zanra1[9];
    char naziv_platforme1[9];
    double cena_igre1;

    while(fscanf(in,"%s %s %s %lf",
        naziv_igre1,
        naziv_zanra1,
        naziv_platforme1,
        &cena_igre1        
    )!=EOF){
        dodaj_u_listu(&(*head),naziv_igre1,naziv_platforme1,naziv_zanra1,cena_igre1);
    }

}

void ispis(IGRA *head){

    if(head==NULL){
        return;
    }

    printf("%s %s %s %lf\n",head->naziv_igre,head->naziv_zanra,head->naziv_platforme,head->cena_igre);
    ispis(head->next);

}