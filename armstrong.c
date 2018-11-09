#include<stdio.h>


int main(){
	
	int n,broj,clan,rez=0;
	printf("Unesite trocifreni broj: ");
	scanf("%d", &n);

	broj = n;
	
	while( broj !=0)
	{
		clan =broj%10;
		rez +=clan*clan*clan;
		broj /=10;
	}
	
	if(rez==n){
		printf("Jeste Armstrongov \n");}
	else{
		printf("Nije Armstongov \n");}
	
	return 0;
}
