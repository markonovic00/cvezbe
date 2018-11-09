#include<stdio.h>
//kelvin je celzijus +273.15
int	main () {
	
	double celzijus, kelvini;	
		
	printf("Unesite temperaturu u celzijusima: ");
	scanf("%lf",&celzijus);
	
	kelvini=celzijus+273.15;
	printf("\nTemperatura u kelvinima je:%lf \n  %p \n",kelvini,&kelvini);	
	
	return 0;
}
