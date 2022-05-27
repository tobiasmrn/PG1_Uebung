#include <stdio.h>

int get_int(char question[]);
int rechnung(int eingabe);

int main() {
    int eingabe = get_int("Ey yo, gib mir bitte eine Nummer :D\n");
    int ergebnis = rechnung(eingabe);
    //Gibt das Ergebnis als Dezimalzahl aus
    printf("Deine Zahl im Dezimalsystem lautet: %f\n", (float) ergebnis);
    //Gibt das Ergebnis als Hexadezimalzahl aus
    printf("Deine Zahl im Hexadezimalsystem lautet: 0x%X\n", ergebnis);
}

//Frägt den User nach einer Zahl und gibt diese zurück
int get_int(char question[]) {
    int a =  0;
    printf("%s", question);
    scanf("%i", &a);
    return a;
}

int rechnung(int x){
    int ergebnis;
    ergebnis = x * (x + 99) / 3;
    return ergebnis;
}