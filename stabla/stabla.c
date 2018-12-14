#include<stdio.h>
#include<stdlib.h>

typedef struct stablo_st{

	int num;
	struct stablo_st *levi;
	struct stablo_st *desni;

} STABLO;

STABLO *novi_el(int num){

	STABLO *novi=malloc(sizeof(STABLO));
	
	novi->num=num;
	novi->levi=NULL;
	novi->desni=NULL;
	
	return novi;
	
}

void dodaj_el(STABLO **root, int num){
	
	STABLO *novi=novi_el(num);
	
	if(*root == NULL){
		*root=novi;
		return;
	}	
	
	if(num < (*root)->num){
		
		dodaj_el(&(*root)->levi,num);
		
	}else{
	
		dodaj_el(&(*root)->desni,num);
	
	}

}

void delete(STABLO **root){

	if(*root != NULL)
	{
	
		delete(&(*root)->levi);
		delete(&(*root)->desni);
		free(*root);
		*root=NULL;
	}

}



void ispis_stabla(STABLO *root){

	if(root != NULL){
		
		ispis_stabla(root->levi);
		printf("%d\n", root->num);
		ispis_stabla(root->desni);
			
	}

}

void initialize(STABLO **root){
	
	*root=NULL;
	
}

int main(int argc, char *argv[]){
	
	STABLO *root;
	
	initialize(&root);
	dodaj_el(&root,5);
	dodaj_el(&root,6);
	dodaj_el(&root,3);
	dodaj_el(&root,4);
	
	ispis_stabla(root);

	delete(&root);	
	
	ispis_stabla(root);
		
	return 0;
}
