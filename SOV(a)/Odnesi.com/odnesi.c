#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
naziv restorana (jedna reč, do 10 karaktera)
vrsta kuhinje (jedna reč, do 20 karaktera)
prosečna ocena korisnika (pozitivan realan broj)
*/

typedef struct restoran_st{

    char naziv[11];
    char vrsta[21];
    double ocena;

    struct restoran_st *left;
    struct restoran_st *right;

} RESTORAN;

FILE *safe_open(char *, char *);
void initialize(RESTORAN **);
RESTORAN *novi_el(char *, char *, double);
void dodaj_el(RESTORAN **,char *, char *, double);
void upisi(RESTORAN **, FILE *);
void ispis(RESTORAN *, FILE *);
void destroy(RESTORAN **);
RESTORAN *get_worst(RESTORAN *);
// Nasa Custom Funkcija Da nadjemo best restoran odredjene vrste
RESTORAN *get_ocena(RESTORAN *root, char *);

int main(int argc, char *argv[])
{
    
    if(argc !=3){
        printf("Zahtevani unos je: ./restorani novi-sad.txt izvestaj.txt\n");
        exit(1);
    }

    RESTORAN *root;
    initialize(&root);

    FILE *in=safe_open(argv[1],"r");
    FILE *out=safe_open(argv[2],"w");

    upisi(&root,in);
    ispis(root,out);

    RESTORAN *worst=get_worst(root);
    if(worst==NULL){
        fprintf(out,"\nNema najgoreg\n");
    }
    else{
        fprintf(out,"\nNajgori je %.1lf %s %s\n",worst->ocena,worst->naziv,worst->vrsta);
    }
    RESTORAN *best = get_ocena(root,"srpski");
    if(best==NULL){
        printf("Ne postoji srpski\n");
    }
    else{
        printf("Najbolji srpski je %.1lf %s %s\n", best->ocena,best->naziv,best->vrsta);
    }

    destroy(&root);

    fclose(in);
    fclose(out);

    return 0;
}

FILE *safe_open(char *filename, char *mode){

    FILE *fp=fopen(filename,mode);

    if(fp==NULL){
        printf("Nije moguce otvoriti %s\n",filename);
        exit(2);
    }

    return fp;

}
void initialize(RESTORAN **root){

    *root=NULL;

}

RESTORAN *novi_el(char *naziv, char *vrsta, double ocena){

    RESTORAN *novi = malloc(sizeof(RESTORAN));

    if(novi==NULL){
        printf("Downolad mor RAM PLIZ\n");
        exit(666);
    }

    strcpy(novi->naziv,naziv);
    strcpy(novi->vrsta,vrsta);
    novi->ocena=ocena;

    novi->left=NULL;
    novi->right=NULL;

    return novi;

}
void dodaj_el(RESTORAN **root,char *naziv, char *vrsta, double ocena){

    RESTORAN *novi=novi_el(naziv,vrsta,ocena);

    if(*root==NULL){
        *root=novi;
        return;
    }

    if((*root)->ocena < novi->ocena){
        dodaj_el(&(*root)->left,naziv,vrsta,ocena);
    }
    else{
        dodaj_el(&(*root)->right,naziv,vrsta,ocena);
    }

}

void upisi(RESTORAN **root, FILE *in){

    char naziv[11];
    char vrsta[21];
    double ocena;
    while(fscanf(in,"%s %s %lf",naziv,vrsta,&ocena)!=EOF){
        dodaj_el(&(*root),naziv,vrsta,ocena);
    }

}

void ispis(RESTORAN *root, FILE *out){

    if(root==NULL){
        return;
    }

    ispis(root->left,out);
    fprintf(out,"%.1lf %s %s\n",root->ocena,root->naziv,root->vrsta);
    ispis(root->right,out);

}

void destroy(RESTORAN **root){

    if(*root==NULL){
        return;
    }

    destroy(&(*root)->left);
    destroy(&(*root)->right);
    free(*root);
    *root=NULL;

}

RESTORAN *get_worst(RESTORAN *root){

    if(root==NULL){
        return NULL;
    }

    if(root->right==NULL){
        return root;
    }

    return get_worst(root->right);

}

RESTORAN *get_ocena(RESTORAN *root, char *vrsta){

    if(root==NULL){
        return NULL;
    }

    RESTORAN *best=NULL;

    if(strcmp(root->vrsta,vrsta)==0){
        best=root;
    }

    RESTORAN *left = get_ocena(root->left,vrsta);

    if(left != NULL){
        if(best==NULL || best->ocena < left->ocena){
            best=left;
        }
    }

    RESTORAN *right= get_ocena(root->right,vrsta);

    if(right!=NULL){
        if(best==NULL || best->ocena < right->ocena){
            best=right;
        }
    }

    return best;

}