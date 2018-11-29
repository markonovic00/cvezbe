#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pacijent_st{

    char ime[20+1];
    char prezime[20+1];
    double holesterol;
    unsigned krvni_pritisak;
    double secer;

} PACIJENT;

typedef struct tip_analize_st{

    char znak;
    char ime[20+1];
    char prezime[20+1];

} ANALIZA;

FILE *safe_open(char *filename, char *mode);
void ucitaj(FILE *in, PACIJENT pacijenti[], int *n);
void formatiraj(PACIJENT pacijenti[],ANALIZA analize[],char *vrsta_analize,int n);
void ispis(FILE *out, ANALIZA analize[], int n);

int main(int argc, char *argv[]){

    if(argc!=4){
        printf("Zeljeni unos je: ./proveri pritisak pacijenti.txt izvestaj.txt\n");
        exit(1);
    }

    int n;
    PACIJENT pacijenti[10];
    ANALIZA analize[10];

    char vrsta_analize[15];
    strcpy(vrsta_analize,argv[1]);

    FILE *in;
    FILE *out;

    in=safe_open(argv[2],"r");
    out=safe_open(argv[3],"w");

    ucitaj(in,pacijenti,&n);
    formatiraj(pacijenti,analize,vrsta_analize,n);
    ispis(out,analize,n);

    fclose(in); 
    fclose(out);

    return 0;

}

FILE *safe_open(char *filename, char *mode){

    FILE *fp=fopen(filename,mode);
    if(fp==NULL){
        printf("Nije moguce ucitati %s\n",filename);
        exit(2);
    }

    return(fp);

}

void ucitaj(FILE *in, PACIJENT pacijenti[], int *n){

    int brojac=0;
    while(fscanf(in,"%s %s %lf %u %lf",
        pacijenti[brojac].ime,
        pacijenti[brojac].prezime,
        &pacijenti[brojac].holesterol,
        &pacijenti[brojac].krvni_pritisak,
        &pacijenti[brojac].secer
    ) != EOF){
        brojac++;
    }
    *n=brojac;

}

void formatiraj(PACIJENT pacijenti[],ANALIZA analize[],char *vrsta_analize,int n){

    int i;
    for(i=0;i<n;i++){

        if(strcmp(vrsta_analize,"pritisak")==0){

            if(pacijenti[i].krvni_pritisak>=90 && pacijenti[i].krvni_pritisak<120){
                analize[i].znak='-';
            }else{
                analize[i].znak='+';
            }

        }else if(strcmp(vrsta_analize,"holesterol")==0){
            
            if(pacijenti[i].holesterol <5.2){
                analize[i].znak='-';
            }else{
                analize[i].znak='+';
            }

        }else if(strcmp(vrsta_analize,"secer")==0){

            if(pacijenti[i].secer>=3.9 && pacijenti[i].secer<5.6){
                analize[i].znak='-';
            }else{
                analize[i].znak='+';
            }

        }

        strcpy(analize[i].ime,pacijenti[i].ime);
        strcpy(analize[i].prezime,pacijenti[i].prezime);

    }

}

void ispis(FILE *out, ANALIZA analize[], int n){

    int i;
    for(i=0;i<n;i++){

        fprintf(out,"%c %s %s\n",analize[i].znak,analize[i].ime,analize[i].prezime);

    }

}