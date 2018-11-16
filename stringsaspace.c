#include<stdio.h>
#include<string.h>

int main(){

	char str1[101], str2[101],str3[101];
	
	printf("(Scanf)Unesite string 1: ");
	scanf("%s",str1); // scanf cita do prvog karaktera
	
	printf("\n%s\n",str1);
	//fflush(stdin); cisti bafer na windowsu
	__fpurge(stdin); //cisti bafer u linuxu
	
	
	printf("(gets)Unesite string 2: ");
	//gets(str2);//Scnaf sve ne valja je puni memoriju
	//puts(str2);//Printf 

	printf("(fgets)Unesite string 3: ");
	fgets(str3,101,stdin);//u koji niz, koliko el,stdin
	printf("\n%s\n",str3);
	
	return 0;
}
