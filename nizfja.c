/*Dat je niz od maksimalno 30 celobrojnih
elemenata. Učitati n elemenata,a zatim omogućiti
korisniku da bira neku od sledećih radnji:
izračunavanje sume elemenata niza, računanje
srednje vrednosti elemenata, nalaženje minimuma,
nalaženje maksimuma. Omogućiti izvršavanje više
radnji (jedna za drugom).*/

#include <stdio.h>
#define MAX_SIZE 30

//Sve funkcije koje cemo koristiti

void unosNiza (int *,int *); //Prvi parametar je pokazivac na niz, a druga je pokazivac brojel niza
void ispisNiza (int *,int); // Prvi parametar je pokazivac na pocetak niza, a drugi je velicina niza
int sumaNiza(int *,int); // Prvi parametar je pokazivac na pocetak niza, a drugi je velicina niza
double srednjaVrednost(int *,int); // Isto kao i kod ostalih
int minNiza(int *,int); // Isto kao i kod ostalih
int maxNiza(int *,int); // Isto kao i kod ostalih

int main(){

    int opcija;
    int brojel;
    int niz[MAX_SIZE];

    do{
        printf("\t Opcije:\n");
        printf("\t1. Unos elemenata niza.\n");
        printf("\t2. Izracunavanje sume.\n");
        printf("\t3. Racunanje srednje vrednosti.\n");
        printf("\t4. Ispis niza.\n");
        printf("\t5. Minimalni element niza.\n");
        printf("\t6. Maksimalni element niza.\n");
        printf("\t7. Izlaz.\n");
        printf("\t>>");
        scanf("%d",&opcija);

        switch(opcija){
            case 1: unosNiza(niz,&brojel);
                    printf("\t  >>Velicina niza je %d \n",brojel); 
                    printf("---------------------------------------------\n");break;
            case 2: printf("\t  >>Suma niza je: %d \n",sumaNiza(niz,brojel)); 
                    printf("---------------------------------------------\n");break;
            case 3: printf("\t  >>Srednja vrednost je: %lf \n",srednjaVrednost(niz,brojel)); 
                    printf("---------------------------------------------\n");break;
            case 4: ispisNiza(niz,brojel);
                    printf("\t  >>Velicina niza je %d \n",brojel); 
                    printf("---------------------------------------------\n");break;
            case 5: printf("\t  >>Minimalni element niza je: %d\n",minNiza(niz,brojel));
                    printf("---------------------------------------------\n");break;
            case 6: printf("\t  >>Maksimalni element niza je: %d\n",maxNiza(niz,brojel));
                    printf("---------------------------------------------\n");break;
        }
    }while(opcija !=7);

    return 0;
}

//Odavde pocinju funkcije

void unosNiza(int *niz, int *brojel){

    do{
        printf("---------------------------------------------\n\n");
        printf("\tUnsite velicinu niza ne vecu od 30: ");
        scanf("%d",brojel);
    }while(*brojel <=0 || *brojel>MAX_SIZE);
    int i;
    for(i=0;i<*brojel;i++){
        printf("\tclan[%d]=",i);
        scanf("%d",(niz+i));//niz je adresa prvog elementa u nizu
    }

}

void ispisNiza(int *niz, int brojel){

    int i;
    printf("---------------------------------------------\n\n");
    printf("\t[");
    for(i=0;i<brojel;i++){
        printf("%d",*(niz+i));// *(niz+i) <=> niz[i]
        if(i!=brojel-1){
            printf(",");
        }
    }
    printf("]\n");

}

int sumaNiza(int *niz,int brojel){

    int suma=0;
    int i;
     printf("---------------------------------------------\n\n");
    for(i=0;i<brojel;i++){
        suma+=niz[i];
    }
    return suma;
}

double srednjaVrednost(int *niz,int brojel){

    double srednja;
    int suma=0;
    int i;
    printf("---------------------------------------------\n\n");
    for(i=0;i<brojel;i++){
        suma+=niz[i];
    }
    srednja=suma/(double)brojel;   
    return srednja;
    
}

int minNiza(int *niz, int brojel){

    int minimum=niz[0];
    int i;
    printf("---------------------------------------------\n\n");
    for(i=0;i<brojel;i++){
        if(niz[i]< minimum){
            minimum=niz[i];
        }
    }
    return minimum;
}

int maxNiza(int *niz, int brojel){

    int maximum=niz[0];
    int i;
    printf("---------------------------------------------\n\n");
    for(i=0;i<brojel;i++){
        if(niz[i]>maximum){
            maximum=niz[i];
        }
    }
    return maximum;
}