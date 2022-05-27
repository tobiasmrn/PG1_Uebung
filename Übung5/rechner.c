#include <stdio.h>
#include <stdlib.h>

int get_number();
char get_opp();
int rechner(int zwischenerg, int number2, char opp);

int main (){
    int number1;
    int number2;
    char opp;
    int zwischenerg = 0;
    int anfang = 1;
    while(1){
        if(anfang ==1){
            number1 = get_number();
            zwischenerg = number1;
        }
        opp = get_opp();
        if(opp == 'q'){
            printf("Das Ergebnis ist: %i.\n", zwischenerg);
            return 0;
        }
        number2 = get_number();
        zwischenerg = rechner(zwischenerg, number2, opp);
        printf("Das aktuelle Zwischenergebnis ist: %i\n", zwischenerg);
        anfang = 0;
    }

}

int get_number(){
    int number;
    printf("Zahl eingeben!\n");
    scanf("%i", &number);
    return number;
}

char get_opp(){
    char opp;
    printf("Operator eingeben!\n");
    while(getchar() != '\n');
    scanf("%c", &opp);
    return opp;
}

int rechner(int zwischenerg, int number2, char opp){
    switch (opp){
        case '+':
            zwischenerg = zwischenerg + number2;
            break;
        case '-':
            zwischenerg = zwischenerg - number2;
            break;
        case '*':
            zwischenerg = zwischenerg * number2;
            break;
        case '/':
            if(number2 == 0){
                printf("Durch 0 geteilt --> ERROR\n");
                exit(420);
            }
            zwischenerg = zwischenerg / number2;
            break;
        case '%':
            zwischenerg = zwischenerg % number2;
            break;
        default:
            break;
    };
    return zwischenerg;
}