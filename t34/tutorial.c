#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct covek_st{
    
    char ime[20+1];
    char prezime[20+1];
    int visina;

} COVEK;

void promeni(char *n);
int saberi(int a,int b);

int main(){

    char c='a';
    char str[10+1]="a";
    int a=10;
    int b=25;
    int c=saberi(a,b);

    promeni(&c);

    COVEK ljudi[10];
    strcpy(ljudi[0].ime,"Marko");
    strcpy(ljudi[1].ime,"Mihajlo");

    return 0;
}

int saberi(int a,int b){

    int rez=a+b;

    return rez;
}

void promeni(char *n){

    *n='a';
}
