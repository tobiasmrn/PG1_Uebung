#include <stdio.h>

int get_input(char question[]);
int input_error_check(int eingabe);
int rechner (int input);
int rechner2 (int  input);

int main(){
    int input = get_input("Bitte geben Sie die obere Grenze der Laufvariable ein: \n");
    int result = rechner(input);
    //Macht es bei sowas wie einer Summe nicht Sinn mit Rekursion zu arbeiten?
    int result2 = rechner2(input);
    printf("Das Ergebnis via for-Schleife ist: %i\nDas Ergebnis via Rekursion ist: %i\n", result, result2);
    return 0;
}

int get_input(char question[]) {
    printf("%s", question);
    int input;
    int checker = 0;
    do{
        scanf("%d", &input);
        checker = input_error_check(input);
    } while (checker == 0);
    return input;
}

int input_error_check(int eingabe) {
    int checker = 1;
    if(eingabe < 1) { //Möglichkeit für einen Errorcheck auf Float?
        checker = 0;
        printf("ERRORCODE 001\nDie Eingabe war nicht erfolgreich. Bitte versuchen Sie es erneut!\n");
    }
    return checker;
}
//for-Schleife
int rechner (int input){
    input++;
    int result = 0;
    for (int i = 0; i < input; i++){
        result = result + (2 * i + 3);
    }
    return result;
}
//Rekursion
int rechner2 (int  input){
    if(input != 0){
        return (2 * input + 3) + rechner2(input - 1);
    }else{
        return 2 * input + 3;
    }
}