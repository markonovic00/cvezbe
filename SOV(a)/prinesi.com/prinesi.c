/*
Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde struktura restoran_st sadrži sledeća polja:

naziv restorana (jedna reč, do 10 karaktera)
vrsta kuhinje (jedna reč, do 20 karaktera)
prosečna ocena korisnika (pozitivan realan broj)
Naravno, struktura restoran_st sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

Na osnovu zadate vrste kuhinje vrsta iz formirane liste upisati podatke u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture restoran_st:

prosečna ocena korisnika (zaokružena na 1 decimalu, koristiti "%3.1f" format specifikator)
naziv restorana (koristiti "%-10s" format specifikator)
vrsta kuhinje
i potom u istu izlaznu datoteku upisati informaciju o najbolje ocenjenom restoranu koji služi hranu zadate vrste kuhinje.

Primer poziva:

./restorani italijanski novi-sad.txt izvestaj.txt
sa vrsta=italijanski i zadatim ulazom u datoteci novi-sad.txt:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct restoran_st{

    char naziv[11];
    char vrsta[21];
    double ocena;

    struct restoran_st *next;

} RESTORAN;

FILE *safe_open(char *,char *,int);
void initialize(RESTORAN **);
RESTORAN *novi_el(char *, char *, double);
void dodaj(RESTORAN **,char *, char *, double);
void upis(RESTORAN **, FILE *);
void ispis(RESTORAN *, FILE *);
void destroy(RESTORAN **);
RESTORAN *get_worst(RESTORAN *, char *);

int main(int argc, char *argv[])
{
    
    if (argc!=4){
        printf("Zeljeni poziv je: ./restorani italijanski novi-sad.txt izvestaj.txt\n");
        exit(666);
    }

    RESTORAN *head;
    initialize(&head);

    FILE *in=safe_open(argv[2],"r",1);
    FILE *out=safe_open(argv[3],"w",2);

    upis(&head,in);
    ispis(head,out);

    RESTORAN *worst=get_worst(head,argv[1]);

    if(worst==NULL){
        fprintf(out,"\nNe postoji\n");
    }else
    {
        fprintf(out,"\nNajgori %.1lf %s %s \n",worst->ocena,worst->vrsta,worst->naziv);
    }

    destroy(&head);

    fclose(in);
    fclose(out);

    return 0;
}

FILE *safe_open(char *filename,char *mode,int error){

    FILE *fp=fopen(filename,mode);

    if(fp==NULL){
        printf("Nije moguce otovoriti %s\n",filename);
        exit(error);
    }

    return fp;

}

void initialize(RESTORAN **head){

    *head=NULL;

}

RESTORAN *novi_el(char *naziv, char *vrsta, double ocena){

    RESTORAN *novi=malloc(sizeof(RESTORAN));

    if(novi==NULL){
        printf("Download moar RAMM \n");
        exit(69);
    }

    strcpy(novi->naziv,naziv);
    strcpy(novi->vrsta,vrsta);
    novi->ocena=ocena;

    novi->next=NULL;

    return novi;

}

void dodaj(RESTORAN **head,char *naziv, char *vrsta, double ocena){

    RESTORAN *novi=novi_el(naziv,vrsta,ocena);

    if(*head==NULL){
        *head=novi;
        return;
    }

    dodaj(&(*head)->next,naziv,vrsta,ocena);

}

void upis(RESTORAN **head, FILE *in){

    char naziv[11];
    char vrsta[21];
    double ocena;
    while(fscanf(in,"%s %s %lf",naziv,vrsta,&ocena)!=EOF){
        dodaj(&(*head),naziv,vrsta,ocena);
    }

}

void ispis(RESTORAN *head, FILE *out){

    if(head==NULL){
        return;
    }

    fprintf(out,"%.1lf %s %s\n",head->ocena,head->naziv,head->vrsta);
    ispis(head->next,out);

}

void destroy(RESTORAN **head){

    if(*head==NULL){
        return;
    } 

    destroy(&(*head)->next);
    free(*head);
    *head=NULL;

}

RESTORAN *get_worst(RESTORAN *head, char *vrsta){

    if(head==NULL){
        return NULL;
    }

    RESTORAN *worst=NULL;
    while(head!=NULL){
    if(strcmp(head->vrsta,vrsta)==0){
        
        if(worst==NULL){
            worst=head;
        }

        if(head->ocena < worst->ocena){
            worst=head;
        }

    }
    head=head->next;
    }
    return worst;
}