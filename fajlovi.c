#include<stdio.h>
#include<stdlib.h>
#include<strng.h>

#define MAX 30

int main(int argc,char *argv[]){
	
	char ime[30];
	char prezime[MAX];
	
	if(argc!=2){
		exit(1);
	}
	
	FILE *out;
	if((out=fopen(argv[1],"w"))==NULL){
		
		printf("\n Greska prilikom otvaranja %s",argv[1]);
		exit(2);
	
	}
	
	fprintf(out,"Ime %s \nPrezime %s","Marko","Novic");
	fclose(out);
	
	FILE *in;
	if((in=fopen(argv[1],"r"))!=NULL){
	
		/*while(fgets(ime,30,argv[1])!=NULL){
			printf("%s\n",ime);
			printf("%s\n",prezime);
		}
	*/
	}
	else{
		
		printf("\n Nemoguce otovoriti datoteku");
		exit(3);
		
	}
	fclose(in);	
	
	
	return 0;
}
