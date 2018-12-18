#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct element_st{
 
    char simbol[3];
    char ime[21];
    double tezina;
    char vrsta[21];

    struct element_st *next;

} ELEMENT;

FILE *safe_open(char *,char *,int);
void initialize(ELEMENT **);
ELEMENT *novi_el(char *, char *, double, char *);
void dodaj_El(ELEMENT **head, char *, char *, double, char *);
void ucitaj(FILE *in, ELEMENT **head);
void ispis(FILE *out, ELEMENT *head);
void destroy(ELEMENT **head);
ELEMENT *get_best(ELEMENT *head, char *vrsta);

int main(int argc, char *argv[])
{
    
    if(argc!=4){
        printf("Trazeni ulaz je: ./najtezi metal uzorak_vino.txt analiza.txt\n");
        exit(1);
    }

    ELEMENT *head;

    initialize(&head);

    FILE *in;
    FILE *out;

    in=safe_open(argv[2],"r",2);
    out=safe_open(argv[3],"w",3);

    ucitaj(in,&head);
    ispis(out,head);

    ELEMENT *best=get_best(head,argv[1]);

    if (best==NULL){
        fprintf(out,"\nNe postoji '%s' vrsta\n",argv[1]);
    }
    else {
        fprintf(out,"\n Najtezi %s je (%s) atomska tezina %lf\n",argv[1],best->simbol,best->tezina);
    }

    destroy(&head);

    fclose(in);
    fclose(out);

    return 0;
}
/* ODAVDE DO DOLE NAPAMET */
FILE *safe_open(char *filename,char *mode,int code){

    FILE *fp=fopen(filename,mode);

    if(fp==NULL){
        printf("Nije moguce otvoriti fajl %s\n",filename);
        exit(code);
    }

    return fp;

}

void initialize(ELEMENT **head){

    *head=NULL;

}

ELEMENT *novi_el(char *simbol, char *ime, double tezina, char *vrsta){

    ELEMENT *novi=malloc(sizeof(ELEMENT));

    if (novi == NULL){
        printf("Nije moguce zauzeti memoriju\n");
        exit(666);
    }

    strcpy(novi->simbol,simbol);
    strcpy(novi->ime,ime);
    novi->tezina=tezina;
    strcpy(novi->vrsta,vrsta);

    novi->next=NULL;

    return novi;
}

void dodaj_El(ELEMENT **head,char *simbol, char *ime, double tezina, char *vrsta){

    ELEMENT *novi = novi_el(simbol,ime,tezina,vrsta);

    if(*head==NULL){
        *head=novi;
        return;
    }

    dodaj_El(&(*head)->next,simbol,ime,tezina,vrsta);

}

void ucitaj(FILE *in, ELEMENT **head){

    char simboltmp[3];
    char imetmp[21];
    double tezinatmp;
    char vrstatmp[21];

    while(fscanf(in,"%s %s %lf %s",
    simboltmp,
    imetmp,
    &tezinatmp,
    vrstatmp
    )!=EOF){
        dodaj_El(&(*head),simboltmp,imetmp,tezinatmp,vrstatmp);
    }

}

void ispis(FILE *out, ELEMENT *head){

    if(head==NULL){
        return;
    }

    fprintf(out,"%s %s %.2lf %s\n",head->simbol,head->ime,head->tezina,head->vrsta);
    ispis(out,head->next);

}

void destroy(ELEMENT **head){

    if(*head==NULL){
        return;
    }

    destroy(&(*head)->next);
    free(*head);
    *head=NULL;

}

ELEMENT *get_best(ELEMENT *head, char *vrsta){

    if(head==NULL){
        return NULL;
    }

    ELEMENT *best=NULL;

    while (head!=NULL){
        if (strcmp(head->vrsta,vrsta)==0){

            if(best==NULL){
                best=head;
            }

            else if(head->tezina > best->tezina){
                best=head;
            }

        }
        head=head->next; 
    }
    return best;

}