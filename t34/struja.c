#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct paket_st{

    char naziv_zemlje[20+1];
    char naziv_operatera[20+1];
    unsigned mesecna_pretplata;
    unsigned KWh_ukljuceni;
    double cena_po_KWh;

} PAKET;

typedef struct cena_st{

    double ukupna_cena;
    char naziv_zemlje[20+1];
    char naziv_operatera[20+1];

} CENA;

FILE *safe_open(char *filename, char *mode);
void ucitaj(FILE *in, PAKET paketi[], int *br_el);
void formatiraj_podatke(PAKET paketi[], CENA cene[], int potroseni_KWh, int br_el);
void ispis(FILE *out, CENA cene[],int br_el);

int main(int argc, char *argv[]){
    
    if(argc != 4){
        printf("Zeljeni format unosa je : ./potrosnja 90 paketi.txt cene.txt\n");
        exit(1);
    }
    int br_el;

    PAKET paketi[10];
    CENA cene[10];

    int potroseni_KWh = atoi(argv[1]);

    FILE *in;
    FILE *out;

    in=safe_open(argv[2],"r");
    out=safe_open(argv[3],"w");

    ucitaj(in, paketi, &br_el);
    formatiraj_podatke(paketi,cene,potroseni_KWh,br_el);
    ispis(out,cene,br_el);

    fclose(in);
    fclose(out);

    return 0;
}

FILE *safe_open(char *filename, char *mode){

    FILE *fp=fopen(filename,mode);

    if(fp==NULL){
        printf("Fajl %s ne moze da se otvori.\n",filename);
        exit(2);
    }

    return fp;

}

void ucitaj(FILE *in, PAKET paketi[], int *br_el){

    int br=0;
    while(fscanf(in,"%s %s %u %u %lf",
        paketi[br].naziv_zemlje,
        paketi[br].naziv_operatera,
        &paketi[br].mesecna_pretplata,
        &paketi[br].KWh_ukljuceni,
        &paketi[br].cena_po_KWh) != EOF){
        br++;
    }
    *br_el=br;
}

void formatiraj_podatke(PAKET paketi[], CENA cene[], int potroseni_KWh, int br_el){

    int i;
    for(i=0; i<br_el; i++){

        if(potroseni_KWh > paketi[i].KWh_ukljuceni){
            
            cene[i].ukupna_cena=(potroseni_KWh-paketi[i].KWh_ukljuceni)*paketi[i].cena_po_KWh+paketi[i].mesecna_pretplata;
            strcpy(cene[i].naziv_zemlje,paketi[i].naziv_zemlje);
            strcpy(cene[i].naziv_operatera,paketi[i].naziv_operatera);
        }

        else if(potroseni_KWh < paketi[i].KWh_ukljuceni){
           
            cene[i].ukupna_cena=paketi[i].mesecna_pretplata;
            strcpy(cene[i].naziv_zemlje,paketi[i].naziv_zemlje);
            strcpy(cene[i].naziv_operatera,paketi[i].naziv_operatera);
        }

    }

}

void ispis(FILE *out, CENA cene[],int br_el){

    int i;
    for(i=0;i<br_el;i++){
        fprintf(out,"%7.2f %s %s\n", cene[i].ukupna_cena, cene[i].naziv_zemlje, cene[i].naziv_operatera);
    }

}