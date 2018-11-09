#include <stdio.h>
#include <math.h>

double hipotenuza (double a,double b);

int main(){
	
	double a,b;
	
	printf("Unesite a: \n");
	scanf("%lf",&a);
	printf("Unesite b: \n");
	scanf("%lf",&b);
	
	printf("Hipotenuza je: %lf \n",hipotenuza(a,b));
	
	return 0;
	
} 

double hipotenuza( double a,double b){

	double c;
	
	c=sqrt(pow(a,2)+pow(b,2));
	
	return c;
}
