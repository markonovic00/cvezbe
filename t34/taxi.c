#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct taxi_st{

    char grad[2+1];
    char naziv[20+1];
    unsigned cena_starta;
    unsigned cena_po_km;

} TAXI;

typedef struct cena_st{

    double ukupna_cena;
    char grad[2+1];
    char naziv[20+1];

} CENA;

FILE *safe_open(char *filename, char *mode); //napamet
void ucitaj(FILE *in, TAXI taksiji[], int *n);
void formatiraj(TAXI taksiji[], CENA cene[], double predjeno, int n);
void ispis(FILE *out, CENA cene[],int n);

int main(int argc, char *argv[]){   //napamet

    if(argc!=4){    //napamet
     
        printf("Zeljeni unos je: ./taxi 9.4 taxi.txt cenetaxi.txt");    //napamet
        exit(1);    //napamet

    }   //napamet

    double predjeno = atof(argv[1]);

    TAXI taksiji[10];
    CENA cene[10];
    int n;

    FILE *in;   //napamet
    FILE *out;  //napamet

    in=safe_open(argv[2],"r");  //napamet
    out=safe_open(argv[3],"w"); //napamet

    ucitaj(in,taksiji,&n);
    formatiraj(taksiji,cene,predjeno,n);
    ispis(out,cene,n);

    fclose(in); //napamet
    fclose(out);    //napamet

    return 0;
}

FILE *safe_open(char *filename, char *mode){ //napamet

    FILE *fp=fopen(filename,mode);

    if(fp==NULL){
        printf("Fajl %s ne moze da se otvori.\n",filename);
        exit(2);
    }

    return fp;

}

void ucitaj(FILE *in, TAXI taksiji[], int *n){

    int br=0; //OBAVEZNO NULA
    while(fscanf(in,"%s %s %u %u",
        taksiji[br].grad,
        taksiji[br].naziv,
        &taksiji[br].cena_starta,
        &taksiji[br].cena_po_km
    )!=EOF){
        br++;
    }
    *n=br;
}

void formatiraj(TAXI taksiji[], CENA cene[], double predjeno, int n){

    int i;
    for(i=0;i<n;i++){
        cene[i].ukupna_cena=taksiji[i].cena_starta+(taksiji[i].cena_po_km*predjeno);
        strcpy(cene[i].naziv,taksiji[i].naziv);
        strcpy(cene[i].grad,taksiji[i].grad); //Kopira iz desnog stringa u levi string
    }

}

void ispis(FILE *out, CENA cene[],int n){

    int i;
    for(i=0;i<n;i++){
        fprintf(out,"%4.0lf %s %s\n",cene[i].ukupna_cena,cene[i].grad,cene[i].naziv);

    }

}