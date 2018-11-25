#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
	
	char str1[101];
	printf("Unesite string : ");
	fgets(str1,101,stdin);
	
	printf("\n%s\n",str1);
	
	int i;
	int duzina = strlen(str1);
	
  	int flag=0;
	printf("%d\n",duzina);
  	
  	for(i=0;i<duzina;i++){
  	
  		if(isalpha(str1[i]) && str1[i] !=' '){
  			str1[i]=tolower(str1[i]);
  			printf("str[%d]=%c | str[%d]=%c\n",i,str1[i],duzina-2-i,str1[duzina-2-i]);
  			if(str1[i]==str1[duzina-i-2]){
  				flag=1;
  			}
  			else if(str1[i]!=str1[duzina-i-2]){
  				flag=0; 			
  			}
  		}
  	}
  	
  	
	if(flag==1){
		printf("\n%s je polindrom",str1);
	}
	else{
		printf("Nije polindrom");
	}

	return 0;
}
