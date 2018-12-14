#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct projekcija_st{

	char oznaka_grada[2+1];
	char naziv_bioskopa[10+1];
	char naziv_filma[8+1];
	char naziv_zanra[9+1];
	unsigned int cena_ulaznice;
	
	struct projekcija_st *left;
	struct projekcija_st *right;

} PROJEKCIJA;

PROJEKCIJA *novi_el(char *grad, char *bioskop, char *film, char *zanr, unsigned cena){

	PROJEKCIJA *novi=malloc(sizeof(PROJEKCIJA));
	
	strcpy(novi->oznaka_grada,grad);
	strcpy(novi->naziv_bioskopa,bioskop);
	strcpy(novi->naziv_filma,film);
	strcpy(novi->naziv_zanra,zanr);
	novi->cena_ulaznice=cena;
	
	novi->left=NULL;
	novi->right=NULL;
	
	return novi;
}

void dodajListu(PROJEKCIJA **root,char *grad, char *bioskop, char *film, char *zanr, unsigned cena){
	
	PROJEKCIJA *novi=novi_el(grad,bioskop,film,zanr,cena);
	
	if(*root == NULL){
		*root=novi;
		return;
	}
	
	if (cena<(*root)->cena_ulaznice){
	
		dodajListu(&(*root)->left,grad,bioskop,film,zanr,cena);
		
	} else {
	
		dodajListu(&(*root)->right,grad,bioskop,film,zanr,cena);
		
	}
	
}

void ispis_stabla(PROJEKCIJA *root){

	if(root != NULL){
		
		ispis_stabla(root->left);
		printf("%s %s %s %s %u\n", root->oznaka_grada,root->naziv_bioskopa,root->naziv_filma,root->naziv_zanra,root->cena_ulaznice);
		ispis_stabla(root->right);
			
	}

}

void initialize(PROJEKCIJA **root){

	*root=NULL;

}

FILE *safe_open(char *,char *);

int main(int argc, char *argv[]){
	
	if (argc != 5){
	
		printf("Ocekivani ulaz je ./povoljne_ulaznice NS Animated projekcije.txt analiza.txt");
		exit(1);
	
	}
	
	PROJEKCIJA *root;	
	
	initialize(&root);
	
	FILE *in = safe_open(argv[3],"r");
	FILE *out = safe_open(argv[4],"w");

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
