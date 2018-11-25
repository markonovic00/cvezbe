#include<stdio.h>

int main(){

    int n=4;
    int m=0;
    m=n++;

    printf("n=%d  m=%d\n",n,m);

    n=4;
    m=0;
    m=++n;

    printf("n=%d  m=%d\n",n,m);

    return 0;
}