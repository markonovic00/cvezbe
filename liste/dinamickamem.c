#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	int *br;
	
	br=(int *)malloc(sizeof(int)); //Mora se kastovati u odgovarajuci tip 
	
	printf("Unesite celi broj: ");
	scanf("%d",br);
	
	printf("Ucitan broj je %d\n",*br);
	
	free(br);

	return 0;
}
