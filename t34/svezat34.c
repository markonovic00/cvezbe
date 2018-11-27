#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct covek_st{

    char ime[20+1];
    char prezime[20+1];
    int visina;

} COVEK ;

void promeni(int *br_el);

int main (int argc, char *argv[]){

    if(argc != 4)

    printf("Broj argumenata je : %d \n",argc);

    int i;
    for(i=0; i<argc;i++){
        printf("argv[%d] = %s\n",i,argv[i]);
    }

    COVEK ljudi[10];

    strcpy(ljudi[0].ime,"Marko");
    puts(ljudi[0].ime);

    int br_el=0;
    printf("1 %d\n",br_el);
    promeni(&br_el);
    printf("2 %d\n",br_el);
    return 0;
}

void promeni(int *br_el){
    *br_el=5;
}