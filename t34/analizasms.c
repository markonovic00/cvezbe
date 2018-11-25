#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct paket_st{
   
    char naziv_provajdera[20+1];
    char naziv_paketa[20+1];
    unsigned mesecna_pretplata;
    unsigned br_besplatnih_poruka;
    double cena_poruke;

} PAKET;

typedef struct cena_st{
    
    double ukupna_cena_paketa;
    char naziv_provajdera[20+1];
    char naziv_paketa[20+1];

} CENA;

FILE *safe_open(char *filename, char *mode);
void ucitaj(FILE *in,PAKET paket[],int *n);
void ispisi(FILE *out,CENA cena[],PAKET paket[],int poslate_poruke,int n);

int main(int argc, char *argv[]){

    if(argc!=4){
        printf("Zeljeni format unosa je ./sms broj ulazni.txt izlazni.txt\n");
        exit(1);
    }

    int poslate_poruke= atoi(argv[1]);
    int n;
    
    FILE *in = safe_open(argv[2],"r");
    FILE *out = safe_open(argv[3],"w");
    
    PAKET paket[10];
    CENA cena[10];
    
    ucitaj(in,paket,&n);
    ispisi(out,cena,paket,poslate_poruke,n);

    fclose(in);
    fclose(out);

    return 0;
}

FILE *safe_open(char *filename, char *mode){

    FILE *fp=fopen(filename,mode);

    if(fp==NULL){
        printf("Can't open file %s\n",filename);
        exit(2);
    }
    return fp;
}

void ucitaj(FILE *in,PAKET paket[],int *n){
    
    int br=0;
    while(fscanf(in,"%s %s %u %u %lf",
    paket[br].naziv_paketa,
    paket[br].naziv_provajdera,
    &paket[br].mesecna_pretplata,
    &paket[br].br_besplatnih_poruka,
    &paket[br].cena_poruke)!=EOF){
        br++;
    }
    *n=br;

}

void ispisi(FILE *out,CENA cena[],PAKET paket[],int poslate_poruke,int n){

    int i;
    for(i=0;i<n;i++){
        if(poslate_poruke<paket[i].br_besplatnih_poruka){
            fprintf(out,"%7.2f %s %s",
            cena[i].ukupna_cena_paketa=paket[i].mesecna_pretplata,
            strcpy(cena[i].naziv_paketa,paket[i].naziv_paketa),
            strcpy(cena[i].naziv_provajdera,paket[i].naziv_provajdera));
        }
        else if(poslate_poruke>paket[i].br_besplatnih_poruka){
            fprintf(out,"%7.2f %s %s\n",
            cena[i].ukupna_cena_paketa=(poslate_poruke-paket[i].br_besplatnih_poruka)*paket[i].cena_poruke+paket[i].mesecna_pretplata,
            strcpy(cena[i].naziv_paketa,paket[i].naziv_paketa),
            strcpy(cena[i].naziv_provajdera,paket[i].naziv_provajdera));
        }
        
    }

}