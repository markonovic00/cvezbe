#include<stdio.h>

int main(){

	char str1[10], *str2; //Uzima samo 9 slova je je 10 znak za kraj '\0'
	
	printf("Unesite string: ");
	scanf("%s",str1);
	str2= str1;
	
	while(*str2){
		printf("%c",*str2++);
	}
	printf("\n%s\n",str1);
	
	return 0;
}
