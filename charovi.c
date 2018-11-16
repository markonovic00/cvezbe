#include<stdio.h>

int main(){

	char znak;
	printf("Unesite znak: ");
	scanf(" %c",&znak);
	printf("Znak kao karakter je: %c\n",znak);
	printf("Numericka vrednost znak-a  je: %d\n",znak);
	printf("Karakter posle %c je %c\n",znak,znak+1);

	
	return 0;
}
