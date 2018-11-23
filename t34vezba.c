#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct taxi_st{
	
	char grad[2+1];
	char naziv[20+1];
	unsigned int cenastarta;
	unsigned cenapokm;
	
} TAXI;

typedef struct cena_st{
	
	float ukupno;
	char grad[2+1];
	char naziv[20+1];
	
} CENA;

FILE *safe_open(char *,char *);
void ucitavanje(FILE *in,TAXI taxies[],int *n);
void mnozenje(TAXI taxies[],CENA cene[], float udanjenost, int n);
void ispis(FILE *out, CENA cene[],int n);

int main(int argc,char *argv[]){
	
	if(argc!=4){
		printf("Proverite broj argumenata nije dobar\n");
		printf("Ocekivani ulaz ./taxi 9.4 taxi.txt cene.txt\n");
		exit(1);
	}
	
	float udaljenost = atof(argv[1]); //pretvara u float atof ,,,, atoi pretvara u int
	TAXI taxies[10];
	CENA cene[10];
	int n;//Velicina niza
	
	FILE *in = safe_open(argv[2],"r");
	FILE *out = safe_open(argv[3],"w");
	
	ucitavanje(in,taxies,&n);
	mnozenje(taxies,cene,udaljenost,n);
	ispis(out,cene,n);
	
	fclose(in);
	fclose(out);
	
	return 0;
}

FILE *safe_open(char *file, char *mode){
	
	FILE *pf = fopen(file, mode);

    if(pf == NULL) {
        printf("File %s ne moze da se otvori\n", file);
        exit(2);
    }

    return pf;
}


void ucitavanje(FILE *in,TAXI taxies[],int *n){
	
	int i=0;
	while(fscanf(in,"%s %s %u %u",
		taxies[i].grad,
		taxies[i].naziv,
		&taxies[i].cenastarta,
		&taxies[i].cenapokm
	)!=EOF){
		i++;
	}	
	*n=i;	
}

void mnozenje(TAXI taxies[], CENA cene[], float udaljenost, int n){

	int i;
	for(i=0; i<=n; i++){
		cene[i].ukupno = taxies[i].cenastarta+taxies[i].cenapokm*udaljenost;
		strcpy(cene[i].grad, taxies[i].grad);
		strcpy(cene[i].naziv, taxies[i].naziv);
	}
	
}

void ispis(FILE *out, CENA cene[],int n){
	
	int i;
	for(i=0;i<n;i++){
		fprintf(out,"%4.0f %s %s\n",
		cene[i].ukupno,
		cene[i].grad,
		cene[i].naziv);
	}		
}





















