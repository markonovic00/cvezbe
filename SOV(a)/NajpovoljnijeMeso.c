#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct meso_st{

    char grad[3];
    char vrsta_mesa[21];
    double cena;

    struct meso_st *next;

} MESO;

FILE *safe_open(char *, char *);
void initialize(MESO **);
MESO *novi(char *, char *, double);
void dodajEl(MESO **, char *, char *, double);
void ucitaj(FILE *, MESO **);
void ispis(FILE *,MESO *);
void kill_pepa(MESO **); // Pepa Pig mhhh (PEPA IZ CRTANOG) moze i destory umesto kill pepa
MESO *get_najpovoljnije(MESO *, char *);

int main(int argc, char *argv[])
{
    
    if (argc != 4){
        printf("Ocekivani ulaz je : ./povoljno_meso junetina cene_mesa.txt analiza.txt\n");
        exit(1);
    }


    MESO *head;

    initialize(&head);

    FILE *in;
    FILE *out;

    in=safe_open(argv[2],"r");
    out=safe_open(argv[3],"w");

    ucitaj(in,&head);
    ispis(out,head);


    MESO *best=get_najpovoljnije(head,argv[1]);
    if(best==NULL){
        fprintf(out,"\n");
        fprintf(out,"Ne postoji %s vrsta mesa\n",argv[1]);
    }
    else {
        fprintf(out,"\n");
        fprintf(out,"Najpovoljnije %s \n %lf %s %s",best->vrsta_mesa,best->cena,best->grad,best->vrsta_mesa);
    }

    kill_pepa(&head);

    fclose(in);
    fclose(out);

    return 0;
}

FILE *safe_open(char *filename, char *mode){

    FILE *fp=fopen(filename,mode);

    if (fp==NULL){
        printf("Nije moguce otvoriti %s\n",filename);
        exit(2);
    }

    return fp;

}

void initialize(MESO **head){

    *head=NULL;

}

MESO *noviEl(char *grad, char *vrsta_mesa, double cena){

    MESO *novi=malloc(sizeof(MESO));

    strcpy(novi->grad,grad);
    strcpy(novi->vrsta_mesa,vrsta_mesa);
    novi->cena=cena;

    novi->next=NULL;

    return novi;

}

void dodajEl(MESO **head, char *grad, char *vrsta_mesa, double cena){

    MESO *novi=noviEl(grad,vrsta_mesa,cena);

    if(*head==NULL){
        *head=novi;
        return;
    }

    dodajEl(&(*head)->next,grad,vrsta_mesa,cena);

}

void ucitaj(FILE *in, MESO **head){
    char grad_tmp[3];
    char vrsta_mesa_tmp[21];
    double cena_tmp;
    while(fscanf(in,"%s %s %lf",
        grad_tmp,
        vrsta_mesa_tmp,
        &cena_tmp
    )!=EOF){
        dodajEl(&(*head),grad_tmp,vrsta_mesa_tmp,cena_tmp);
    };

}

void ispis(FILE *out,MESO *head){

    if(head==NULL){
        return;
    }
    fprintf(out,"%s %s %lf\n",head->grad,head->vrsta_mesa,head->cena);
    ispis(out,head->next);

}

void kill_pepa(MESO **head){

    if(*head==NULL){
        return;
    }

    kill_pepa(&(*head)->next);
    free(*head);
    *head==NULL;

}

MESO *get_najpovoljnije(MESO *head, char *vrsta_mesa){

    if(head==NULL){
        return NULL;
    }

    MESO *best=NULL;

    while(head!=NULL){

        if(strcmp(head->vrsta_mesa,vrsta_mesa)==0){

            if(best==NULL){

                best=head;

            } else if(head->cena < best->cena){

                best=head;

            }

        }

        head=head->next;

    }

    return best;

}
