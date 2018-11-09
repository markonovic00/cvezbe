#include <stdio.h>

int main(){
	int n=10;
	int niz[n];
	
	int *pn;
	int i;
	int clan;
	pn=niz;
	
	for(i=0;i<n;i++){		
		printf("Unesite clan[%d]:",i);
		scanf("%d",(pn+i));		
	}
	for(i=0;i<n/2;i++){
			clan=*(pn+i);
			*(pn+i)=*(pn+n-1-i);
			*(pn+n-1-i)=clan;	
	}
	for(i=0;i<n;i++){
		printf("Clan[%d]=%d\n",i,*(pn+i));
	}
	
	return 0;
}
