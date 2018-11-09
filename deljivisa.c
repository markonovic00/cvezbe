#include<stdio.h>

int main(){

	int n,q;
	
	printf("Unesite granicnu vrednost:");
	scanf("%d",&n);
	printf("Unesite delilac:");
	scanf("%d",&q);
	int i;
	for(i=1; i<=n;i++)
	{
		if(i%q==0)
			printf("Ovaj broj je deljiv %d sa q\n",i);
	}		

	return 0;
}
