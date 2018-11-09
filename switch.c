#include<stdio.h>

int main(){

	int a=1;
	
	do{
	
	printf("Unesite ocenu: \n");
	scanf("%d",&a);
	
		switch (a){
			case 1:
				printf("Nedovoljan\n");
				break;
			case 2:
				printf("Dovoljan\n");
				break;
			case 3:
				printf("Dobar\n");
				break;
			case 4:
				printf("Vrlo Dobar\n");
				break;
			case 5:
				printf("Odlican\n");
				break;
			default:
				printf("Ocena mora biti izmedju 1 i 5 \n");
			}			
	} while(a<1 || a>5); //Naredbe u do while idu kontra od ostalih...
	return 0;
}
