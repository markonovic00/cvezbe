#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct gorivo_st{

    char grad[3];
    char tip[11];
    double cena;

    struct gorivo_st *next;

} GORIVO;

FILE *safe_open(char *,char *);
void initialize(GORIVO **);
GORIVO *novi_el(char *, char *, double);
void dodaj_u_listu(GORIVO **,char *, char *, double);
void upisi(FILE *, GORIVO **);
void ispis(FILE *, GORIVO *);
void destroy(GORIVO **);
void get_prosek(GORIVO *,FILE *, char *);

int main(int argc, char *argv[])
{
    
    if(argc != 4){
        printf("Zeljeni unos je: ./gorivo benzin cene.txt izvestaj.txt\n");
        exit(1);
    }

    FILE *in;
    FILE *out;

    GORIVO *head;

    initialize(&head);

    in=safe_open(argv[2],"r");
    out=safe_open(argv[3],"w");

    upisi(in,&head);
    ispis(out,head);

    get_prosek(head,out,argv[1]);

    destroy(&head);

    fclose(out);
    fclose(in);

    return 0;
}

FILE *safe_open(char *filename,char *mode){

    FILE *fp=fopen(filename,mode);
    
    if(fp==NULL){
        printf("Nije uspesno otvoren %s\n",filename);
        exit(2);
    }

    return fp;

}

void initialize(GORIVO **head){

    *head=NULL;

}

GORIVO *novi_el(char *grad, char *tip, double cena){

    GORIVO *novi=malloc(sizeof(GORIVO));

    if(novi==NULL){
        printf("Nije uspesno zauzeta memorija\n");
        exit(3);
    }

    strcpy(novi->grad,grad);
    strcpy(novi->tip,tip);
    novi->cena=cena;
    novi->next=NULL;

    return novi;
}

void dodaj_u_listu(GORIVO **head,char *grad, char *tip, double cena){

    GORIVO *novi=novi_el(grad,tip,cena);

    if(*head==NULL){
        *head=novi;
        return;
    }

    dodaj_u_listu(&(*head)->next,grad,tip,cena);

}

void upisi(FILE *in, GORIVO **head){

    char grad[3];
    char tip[11];
    double cena;
    while(fscanf(in,"%s %s %lf",
        grad,
        tip,
        &cena
    )!=EOF){
        dodaj_u_listu(&(*head),grad,tip,cena);
    }

}

void ispis(FILE *out, GORIVO *head){

    if(head==NULL){
        return;
    }

    fprintf(out,"%.2lf %s %s\n",head->cena,head->tip,head->grad);
    ispis(out,head->next);

}

void destroy(GORIVO **head){

    if(*head==NULL){
        return;
    }

    destroy(&(*head)->next);
    free(*head);
    *head=NULL;

}

void get_prosek(GORIVO *head,FILE *out, char *tip){

    int count=0;
    double suma=0;

    while(head!=NULL){

        if(strcmp(tip,head->tip)==0){
            count++;
            suma=suma+head->cena;
        }
        head=head->next;
    }
    if(count > 0){

        double prosek = suma/count;
        fprintf(out,"\nAVG = %.2lf\n",prosek);
    }
    else
    {
        fprintf(out,"\nNe postoji to gorivo\n");
        return;
    }
    

}