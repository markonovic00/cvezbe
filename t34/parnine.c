#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 30

void ispis(int niz[], char *tip, int velicina);

int main(){

    int n;
    do{ 
        printf("Unesite velicinu niza: \n");
        scanf("%d",&n);

    }while(n<0 || n>MAX_SIZE);

    int i;
    int niz[MAX_SIZE];
    
    for(i=0;i<n;i++){
        printf("\nNiz[%d]: ",i);
        scanf("%d",&niz[i]);
    }

    int pa[MAX_SIZE];
    int ne[MAX_SIZE];

    int parni=0;
    int neparni=0;

    for(i=0; i<n; i++){
        if(niz[i]%2==0){
            pa[parni]=niz[i];
            parni++;
        }
        else if(niz[i]%2==1){
            ne[neparni]=niz[i];
            neparni++;
        }
    }

    ispis(niz,"Niz",n);
    ispis(pa,"Parni",parni);
    ispis(ne,"Neparni",neparni);



    return 0;
}

void ispis(int niz[], char *tip, int velicina){

    int i=0;
    puts(tip);
    printf("\n[");
    for(i;i<velicina;i++){
        printf("%d ",niz[i]);
    }
    puts("]");

}