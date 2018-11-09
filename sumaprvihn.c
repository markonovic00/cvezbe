#include<stdio.h>

int main(){
	
	int n;
	printf("Unesite granicnu vrednost: ");
	scanf("%d", &n);
	int i;
	int suma=0;
	for(i=0; i<=n; i++){
		suma+=i;
	}
	
	printf("Suma je: %d \n",suma);
	
	return 0;
}
