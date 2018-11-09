#include <stdio.h>

int main(){
	
	int n=0;
	printf("unesite granicnu vrednost: \n");
	scanf("%d",&n);
	int i;
	int fakt=1;
	for(i=1;i<=n;i++){
		fakt *=i;
	}
	printf("Faktorijal %d\n",fakt);
	return 0;
}
