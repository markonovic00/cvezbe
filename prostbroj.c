#include <stdio.h>

int main(){
	
	int n;
	
	printf("Unesite broj: \n");
	scanf("%d",&n);
	int i;
	for(i=1; i<=n;i++){
		
		if(n%i==0 && i==n){
			printf("nije prost \n");
			break;
			}
			else{
			printf("Broj je prost \n");
			}
	}
		

	return 0;
}
