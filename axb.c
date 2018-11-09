// ax + b = 0, x = -b/a
#include <stdio.h>

int main(){

	double a,b;
	char x='y';
	do{
	printf("Unesite a i b \n");
	scanf("%lf %lf",&a,&b);
	
	if(a==0 && b==0)
		printf("Rezultat je 0\n");
	else if(a==0)
		printf("Deljenje sa nulom ne znamo rezultat\n");
	else
		printf("Rezultat je: %lf \n", (-b/a));
		
	printf("Da li zelite da nstavite racunanje y/n ? \n");
	scanf("%c",&x);
	} while(x!='n');
	
	
	return 0;
}
