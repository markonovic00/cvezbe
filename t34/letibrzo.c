#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct prevoznik_st{
    
    char naziv[20+1];
    double cena_karte;
    double masa_besplatnog_prtljaga;
    double prekomerni_pokg;

} PREVOZNIK;

typedef struct cene_st{

    double ukupna_cena;
    char naziv[20+1];

} CENE;

FILE *safe_open(char *filename, char *mode);
void load_data(FILE *in, PREVOZNIK prevoznici[], int *el);
void format_data(PREVOZNIK prevoznici[],CENE cene[],double tezina,int elements);
void write_data(FILE *out, CENE cene[],int elements);

int main(int argc,char *argv[]){

    if(argc!=4){
        
        printf("Ocekivani format unosa je ./letovi 23.5 avioprevoznici.txt cene.txt\n");
        exit(1);
    
    }
    int elements;

    FILE *in;
    FILE *out;

    double tezina_prtljaga=atof(argv[1]);

    PREVOZNIK prevoznici[10];
    CENE cene[10];

    in=safe_open(argv[2],"r");
    out=safe_open(argv[3],"w");

    load_data(in,prevoznici,&elements);
    format_data(prevoznici,cene,tezina_prtljaga,elements);
    write_data(out,cene,elements);

    fclose(in);
    fclose(out);

    return 0;
}

FILE *safe_open(char *filename, char *mode){

    FILE *fp;
    fp=fopen(filename,mode);

    if(fp==NULL){
        printf("Nije moguce otvoriti fajl %s\n",filename);
        exit(2);
    }

    return fp;

}

void load_data(FILE *in, PREVOZNIK prevoznici[], int *el){

    int i=0;
    while(fscanf(in,"%s %lf %lf %lf",
        prevoznici[i].naziv,
        &prevoznici[i].cena_karte,
        &prevoznici[i].masa_besplatnog_prtljaga,
        &prevoznici[i].prekomerni_pokg
        )!=EOF){
        i++;
    }
    *el=i;

}

void format_data(PREVOZNIK prevoznici[],CENE cene[],double tezina, int elements){

    int i;
    for(i=0;i<elements;i++){
        if(tezina<=prevoznici[i].masa_besplatnog_prtljaga){
            strcpy(cene[i].naziv,prevoznici[i].naziv);
            cene[i].ukupna_cena=prevoznici[i].cena_karte;
        }
        else if(tezina>prevoznici[i].masa_besplatnog_prtljaga){
            strcpy(cene[i].naziv,prevoznici[i].naziv);
            cene[i].ukupna_cena=(tezina-prevoznici[i].masa_besplatnog_prtljaga)*prevoznici[i].prekomerni_pokg+prevoznici[i].cena_karte;
        }
        else
        {
            printf("Unkown error\n");
            exit(3);
        }
    }

}

void write_data(FILE *out, CENE cene[],int elements){

    int i;
    for(i=0;i<elements;i++){

        fprintf(out,"%7.2lf %s\n",
            cene[i].ukupna_cena,
            cene[i].naziv
        );

    }

}