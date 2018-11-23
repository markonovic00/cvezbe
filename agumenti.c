#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
	
	if(argc==2){
		printf("Tu su svi argumenti %s\n",argv[1]);
	}
	else if(argc >2){
		printf("Uneli ste previse\n");
	}
	else if(argc <2){
		printf("Unesite barem 1 argument\n");
	}
	
	return 0;
}
