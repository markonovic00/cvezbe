#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

    if(argc != 4){
        printf("Zeljeni format je ./proveri pritisak pacijenti.txt izvestaj.txt\n");
        exit(1);
    }
    return 0;
}