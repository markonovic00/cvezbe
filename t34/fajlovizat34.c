#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct covek_st{

    char ime[20+1];
    char prezime[20+1];
    int br_indeksa;

} COVEK;

FILE *safe_open(char *filename,char *mode);
void ucitaj(FILE *in, COVEK ljudi[], int *br_podataka);
void ispisinaekran(COVEK ljudi[],int br_podataka);

int main(int argc, char *argv[]){

    if(argc != 2){
        printf("Zeljeni format unosa je: ./fajlovi vezba.txt\n");
        exit(1);
    }

    int br_elemenata;
    COVEK ljudi[10];

    FILE *in;

    in = safe_open(argv[1],"r");
    ucitaj(in,ljudi,&br_elemenata);
    ispisinaekran(ljudi,br_elemenata);

    fclose(in);

    return 0;
}

FILE *safe_open(char *filename,char *mode){

    FILE *fp=fopen(filename,mode);

    if(fp==NULL){
        printf("Fajl %s nije moguce otvoriti\n",filename);
        exit(2);
    }

    return fp;

}

void ucitaj(FILE *in, COVEK ljudi[], int *br_podataka){

    int brojac=0;
    
    while(fscanf(in,"%s %s %d",
        ljudi[brojac].ime,
        ljudi[brojac].prezime,
        &ljudi[brojac].br_indeksa
    )!= EOF){
        brojac++;
    };

    *br_podataka=brojac;

}

void ispisinaekran(COVEK ljudi[],int br_podataka){

    int i;
    for(i=0; i<br_podataka; i++){
        printf("%s %s %d\n",ljudi[i].ime,ljudi[i].prezime, ljudi[i].br_indeksa);
    }

}