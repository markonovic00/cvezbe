#include<stdio.h>
#include<string.h>

int main(){
	
	char str1[101],*str2;
	
	int duzina;
	
	printf("Unesite string str1: ");
	fgets(str1,101,stdin);
	duzina=strlen(str1);
	printf("\n%s\n",str1);
	int i;
	for(i=duzina;i>=0;i--){
		printf("%c",str1[i]);
	}
	
	printf("\n");
	
	int brojac=0;
	str2=str1;	
	while(*str2){
		brojac++;	
		str2++;
	}
	
	printf("brojac %d\n",brojac-1);
	
	return 0;
}
