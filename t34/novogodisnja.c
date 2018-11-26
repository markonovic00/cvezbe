#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct zelja_st{

    unsigned int br_gostiju;
    char naziv_pice[20+1];

} ZELJA;

typedef struct porudzbina_st{

    double br_parcadi;
    unsigned celepice;
    char naziv_pice[20+1];

} PORUDZBINA;

FILE *safe_open(char *filename, char *mode);
void ucitaj(FILE *in,ZELJA zelje[], int *br_el);
void formatiranje(ZELJA zelje[], PORUDZBINA porudzbe[],double apetit, int br_el);
void ispis(FILE *out,PORUDZBINA porudzbe[],int br_el);

int main(int argc,char *argv[]){

    if(argc != 4){
        printf("Zeljeni unos je ./zurka 2.5 zelje.txt nabavka.txt\n");
        exit(1);
    }
    
    int br_el;
    ZELJA zelje[10];
    PORUDZBINA porudzbe[10];
    double apetit = atof(argv[1]);

    FILE *in;
    FILE *out;
    
    in=safe_open(argv[2],"r");
    out=safe_open(argv[3],"w");

    ucitaj(in, zelje, &br_el);
    formatiranje(zelje,porudzbe,apetit,br_el);
    ispis(out,porudzbe,br_el);

    fclose(in);
    fclose(out);

    return 0;
}

FILE *safe_open(char *filename, char *mode){

    FILE *fp=fopen(filename,mode);
    
    if(fp==NULL){
        printf("Fajl nije uspesno otvoren %s\n",filename);
        exit(2);
    }

    return fp;

}

void ucitaj(FILE *in,ZELJA zelje[], int *br_el){

    int br=0;
    while(fscanf(in,"%u %s",
        &zelje[br].br_gostiju,
        zelje[br].naziv_pice) != EOF){
        br++;
    }
    *br_el=br;
}

void formatiranje(ZELJA zelje[], PORUDZBINA porudzbe[], double apetit, int br_el){

    int parcadi_pice = 8; // Jer svaka pica ima 8 parcadi
    int i;
    for(i=0; i<br_el;i++){

        porudzbe[i].br_parcadi = zelje[i].br_gostiju*apetit;
        porudzbe[i].celepice=ceil(porudzbe[i].br_parcadi/parcadi_pice);
        strcpy(porudzbe[i].naziv_pice,zelje[i].naziv_pice);

    }

}

void ispis(FILE *out,PORUDZBINA porudzbe[],int br_el){

    int i;
    for(i=0;i<br_el;i++){

        fprintf(out,"%5.1lf %2u %s\n",
            porudzbe[i].br_parcadi,
            porudzbe[i].celepice,
            porudzbe[i].naziv_pice
        );

    }

}