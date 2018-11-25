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
void ucitaj(FILE *filename, PACIJENT pacijenti[], int *n);
void ispisi(FILE *filename,PACIJENT pacijenti[],ANALIZA analiza[],char *tip_an,int n);

int main(int argc, char *argv[]){

    if(argc!=4){
    
       printf("Trazeni unos je ./proveri pritisak pacijenti.txt izvestaj.txt\n");
       exit(1);
    
    }

    FILE *in;
    FILE *out;
    
    int n;
    char tip_an[15];
    strcpy(tip_an,argv[1]);

    in=safe_open(argv[2],"r");
    out=safe_open(argv[3],"w");

    PACIJENT pacijenti[10];
    ANALIZA analiza[10];

    ucitaj(in,pacijenti,&n);
    ispisi(out,pacijenti,analiza,tip_an,n);

    fclose(in);
    fclose(out);

    return 0;
}

FILE *safe_open(char *filename,char *mode){
    
    FILE *fp = fopen(filename,mode);

    if(fp==NULL){
        printf("File %s nije moguce otvoriti.\n",filename);
        exit(2);
    }

    return fp;
}

void ucitaj(FILE *filename, PACIJENT pacijenti[], int *n){

    int br=0;
    while(fscanf(filename,"%s %s %lf %u %lf",
        pacijenti[br].ime,
        pacijenti[br].prezime,
        &pacijenti[br].holesterol,
        &pacijenti[br].krvni_pritisak,
        &pacijenti[br].secer
    ) != EOF ){
        br++;
    }

    *n=br;

}

void ispisi(FILE *filename,PACIJENT pacijenti[],ANALIZA analiza[],char *tip_an,int n){

    int i;
    char znak;
    for(i=0;i<n;i++){
        if(strcmp(tip_an,"pritisak")==0){
            if(pacijenti[i].krvni_pritisak<120 && pacijenti[i].krvni_pritisak>=90){
                znak='-';
            }
            else{
                znak='+';
            }
        }
        else if(strcmp(tip_an,"holesterol")==0){
            if(pacijenti[i].holesterol<5.2){
                znak='-';
            }
            else{
                znak='+';
            }
        }
        else if(strcmp(tip_an,"secer")==0){
            if(pacijenti[i].secer<5.6 && pacijenti[i].secer>=3.9){
                znak='-';
            }
            else{
                znak='+';
            }
        }
        else{
            printf("Nepoznata analiza");
            exit(3);
        }
        fprintf(filename,"%c %s %s\n",
        analiza[i].znak=znak,
        strcpy(analiza[i].ime,pacijenti[i].ime),
        strcpy(analiza[i].prezime,pacijenti[i].prezime)
        );

    }

}