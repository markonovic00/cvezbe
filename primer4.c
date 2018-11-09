#include<stdio.h>
#include<math.h>

int main(){
	
	int a,b,c;
	
	printf("Unesite broj a:");
	scanf("%d",&a);
	
	printf("Unesite broj b:");
	scanf("%d",&b);
	
	printf("Unesite broj c:");
	scanf("%d",&c);
	
	double art,har,geo,kv;
	
	art=(a+b+c)/3.0;
	har=3.0/((1.0/a)+(1.0/b)+(1.0/c));
	geo=pow(a*b*c,1/3.0);
	kv=sqrt((a*a+b*b+c*c)/3.0);
	
	printf("Aritmeticka sredina:%lf\n",art);
	printf("Harmonijska sredina:%lf\n",har);
	printf("Geometrijska sredina:%lf\n",geo);
	printf("Kvadratna sredina:%lf\n",kv);
	

	return 0;
}
