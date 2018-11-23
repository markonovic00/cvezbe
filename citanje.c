#include<stdio.h>
#include<stdlib.h>
#include<string.h>


FILE *safe_open(char *, char *);
void prebrojavanje (FILE *,FILE *);

int main(int argc,char *argv[]){

	if(argc !=3){
		printf("Nije odgovarajuci broj parametara");
		exit(1);
	}
	
	FILE *in = safe_open(argv[1],"r");
	FILE *out = safe_open(argv[2],"w");
	
	prebrojavanje(in,out);
	
	fclose(in);
	fclose(out);
	
	return 0;
}

FILE *safe_open(char *file, char *mode){  ///sigurno na test
	
	FILE *pf = fopen(file, mode);

    if(pf == NULL) {
        printf("File %s ne moze da se otvori\n", file);
        exit(2);
    }

    return pf;

}

void prebrojavanje (FILE *in,FILE *out){
	
	char str[100+1];
	int duzina=0;
	int br=0;
	char naj[100+1];
	while(fscanf(in,"%s",str) != EOF){//cita iz fajla red po red
		br++;
		if(strlen(str)>duzina){
			duzina=strlen(str);
			strcpy(naj,str);
		}
	}
	
	fprintf(out,"Broj reci je %d, a najduza rec je %s\n",br,naj);

}
