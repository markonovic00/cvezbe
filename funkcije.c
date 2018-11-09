#include <stdio.h>
#include <stdlib.h>

float power(float x, int k);

int main(){

	printf("Stepenovanje %.2f na %d i rez je: %.2f\n",2.0,3,power(2.0,3));
	
	return EXIT_SUCCESS;

}

float power(float x,int k){
	
	int i;
	float result=1;
	for(i=0;i<k;i++)
		result*=x;
	
	return result;
}
