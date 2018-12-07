#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

	int n;
	int *a;
	int i,max;
	
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	
	a=(int *)malloc(n*sizeof(int));
	if (a==NULL){
		printf("Greska pri zauzimanju memorije\n");
		exit(1);
	}
	
	for (i=0;i<n;i++){
		
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	
	max=a[0];
	for(i=1;i<n;i++){
	
		if (a[i]>max){
			max=a[i];
		}
	}
	printf("Najveci el je %d\n",max);
	free(a);
		
	return 0;
}
