#include <stdio.h>

int get_input_euro(char question[]);
float get_input_cent(char question[]);
int errorcheckEuro (int eingabe);
int errorcheckCent (int eingabe);
int rechner (int eingabe, float want_ausgabe);
int ausgabe (int eingabe, float want_ausgabe, int faktor);

int main() {
    int eingabe = get_input_euro("Bitte geb deinen Betrag ein: ");
    float want_ausgabe = get_input_cent("Welche Cent Münzen wollen Sie haben?\n");
    int faktor = rechner(eingabe, want_ausgabe);
    ausgabe(eingabe, want_ausgabe, faktor);
    return 0;
}

int errorcheckEuro (int eingabe) {
    int checker = 1;
    if(eingabe % 5 != 0) {
        checker = 0;
    }
    return checker;
}

int get_input_euro(char question[]) {
    printf("%s", question);
    int input;
    int checker = 0;
    do{
        scanf("%d", &input);
        checker = errorcheckEuro(input);
        if(checker == 0){
            printf("Ey yo Chef! Wir haben nen' Error!\n");
        }
    } while (checker == 0);
    return input;
}

int errorcheckCent (int eingabe) {
    int checker = 1;
    switch (eingabe){
        case 5:
            checker = 1;
            break;
        case 10:
            checker = 1;
            break;
        case 20:
            checker = 1;
            break;
        case 50:
            checker = 1;
            break;
        default:
            checker = 0;
            break;
    }
    return checker;
}

float get_input_cent(char question[]) {
    printf("%s", question);
    int input;
    int checker;
    float coin;
    do{
        scanf("%d", &input);
        checker = errorcheckCent(input);
        if(checker == 0){
            printf("Ey yo Chef! Wir haben nen' Error!\n");
        }
    }while (checker == 0);
    switch (input) {
        case 5:
            return 0.05;
            break;
        case 10:
            return 0.1;
            break;
        case 20:
            return 0.2;
            break;
        case 50:
            return 0.5;
            break;
        default:
            printf("Ey yo Chef! Wir haben nen' Error!\n");
            break;
    }
    return 0;
}

int rechner (int eingabe, float want_ausgabe){
    int ergebnis = eingabe / want_ausgabe;
    return ergebnis;
}

int ausgabe (int eingabe, float want_ausgabe, int faktor){
    int cents = want_ausgabe * 100;
    printf("So ditte hat alles jut funktioniert! Ihre %d Euro werden ihnen nun in %d %d-Cent Münzen ausgegeben!\n", eingabe, faktor, cents);
    return 0;
}

