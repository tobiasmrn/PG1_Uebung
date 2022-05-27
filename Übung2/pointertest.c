#include <stdio.h>

void rechner(int z1, int z2, int *erg ){
    *erg = z1*z2;
}

int main (){
    int a = 7;
    int b = 7;
    int c;
    int * p1 = &a;
    int ** p2 = &p1;
    int *** p3 = &p2;
    int **** p4 = &p3;
    int ***** p5 = &p4;
    printf("Zahl1: %i\n", *****p5);
    printf("Speicherort Zahl: %p\n", &a);
    printf("Speicherort Zahl: %p\n", p1);
    printf("Speicherort Pointer 1: %p\n", &p1);
    rechner(a,b,&c);
    printf("7x7 = %d\n", c);
}

