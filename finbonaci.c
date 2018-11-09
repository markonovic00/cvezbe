#include<stdio.h>

int main(){

	int i;
	int n[100]={0};
	n[0]=1;
	n[1]=1;
	for(i=0;i<100;i++){
	
		if(n[i+2]<=1000)
		{
			n[i+2]=n[i]+n[i+1];
			printf("Clan [%d] : %d \n",i,n[i]);
		}
		if(n[i+1]>1000){
			break;
		}
	
	}	
	
	return 0;
}
