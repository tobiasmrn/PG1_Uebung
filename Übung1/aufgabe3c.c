/*
bei 65000 kommt es zu einem integer overflow --> zu wenig Speicherplatz für die
Größe des Ergebnisses --> "Rutschen in negativen Bereich"

Im Folgenden wurde der Quellcode aus 3a so abgeändert, dass es bei der Eingabe "65000" nicht zu einem 
Overflow kommt.
*/
#include <stdio.h>

int get_long(char question[]);
long rechnung(long eingabe);

int main() {
    long eingabe = get_long("Ey yo, gib mir bitte eine Zahl :D\n");
    long ergebnis = rechnung(eingabe);
    //Gibt das Ergebnis als Dezimalzahl aus
    printf("Deine Zahl im Dezimalsystem lautet: %li\n", ergebnis);
    //Gibt das Ergebnis als Hexadezimalzahl aus
    printf("Deine Zahl im Hexadezimalsystem lautet: 0x%lX\n", ergebnis);
    return 0;
}

//Frägt den User nach einer Zahl und gibt diese zurück
int get_long(char question[]) {
    int a =  0;
    printf("%s", question);
    scanf("%i", &a);
    return a;
}

long rechnung(long x){
    long ergebnis;
    ergebnis = x * (x + 99) / 3;
    return ergebnis;
}