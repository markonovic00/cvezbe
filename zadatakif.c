#include <stdio.h>
#include <math.h>

int main (){
	
	double x;
	

	scanf("%lf",&x);
	
	if(x<0)
		printf("y=-7\n");
	else if(0<=x && x<1)
		printf("%lf \n",pow(x,1/4.0));
	else if(1<=x && x<13)
		printf("%lf \n", sqrt(2*x));
	else if(x>=13)
		printf("%lf \n",pow(x,2)/9.0);
	
	return 0;
}
