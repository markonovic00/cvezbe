#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ispis(int niz[],int vel);
void sort(int niz[], int red,int vel);

int main(){

    int niz[10];
    int i;
    for(i = 0 ;i<10;i++){
        niz[i] = rand()%50; 
    }

    ispis(niz,10);
    sort(niz,1,10);

    return 0;
}

void ispis(int niz[],int vel){

    printf("\n[");
    int i;
    for(i=0;i<vel;i++){
        printf("%d ",niz[i]);
    }
    puts("]");

}

void sort(int niz[],int red,int vel){
    int i;
    int manji=niz[0];
    for(i=0; i<vel;i++){
        
        if(i==0){

        }
        else if(i>0 && niz[i]<niz[i-1]){
            manji=niz[i];
            niz[i-1]=niz[i];
            niz[i]=manji;
        }
    }    

}