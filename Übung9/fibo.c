#include <stdio.h>

/*
Für die "Normale" Berechnung brauche ich für die n-te Fibonaccizahl ca. n Durchläufe --> Big-O von n
Für die "Rekursive" Berechnung brauche ich für die n-te Fibonaccizahl ca n*2n Durchläufe --> Big-O von n^2
--> Die rekursive Funktion wird v.a. bei großen zahlen wesentlich länger brauchen!
*/


void normal();
void rekursion();
long fib_rek(int number);

//Test

int main (){
    int choose = 5;
    printf("\nBitte wählen wählen Sie über Eingabe ob Sie 'NORMAL'(0) rechnen wollen, oder über 'REKURSION'(1)!\n");
    scanf("%i", &choose);
    switch(choose){
        case 0:
            normal();
            break;
        case 1:
            rekursion();
            break;
        default:
            printf("ERROR\n");
            break;
    };
    return 0;
}

void normal(){
    int number = 0;
    long act = 1;
    long prev = 1;
    printf("Die wie vielte Fibonaccizahl wollen Sie haben?\n");
    scanf("%i", &number);
    if(number < 0){
        printf("Eingabe nicht gültig, das Programm wird beendet!\n");
        return;
    }
    switch(number){
        case 0:
           printf("Das Ergebnis ist: 0\n"); 
           break;
        case 1:
            printf("Das Ergebnis ist: 1\n"); 
            break;
        case 2:
            printf("Das Ergebnis ist: 1\n"); 
            break;
        default:
            for(int i = 0; i < number - 2; i++){
                int swap = 0;
                swap = act;
                act += prev;
                prev = swap;
            }
            printf("Das Ergebnis ist: %ld\n", act);
            break;
    }
    return;
}

void rekursion(){
    int number = 0;
    printf("Die wie vielte Fibonaccizahl wollen Sie haben?\n");
    scanf("%i", &number);
    if(number < 0){
        printf("Eingabe nicht gültig, das Programm wird beendet!\n");
        return;
    }
    long fib = fib_rek(number);
    printf("Das Ergebnis ist: %ld\n", fib);
    return;
}

long fib_rek(int number){
    switch(number){
        case 0:
            return 0;
            break;
        case 1: 
            return 1;
            break;
        case 2:
            return 1;
            break;
        default:
            return fib_rek(number - 1) + fib_rek(number - 2);
            break;
    }
}