/*
a)
Gegeben: 
    - Feste Anzahl an Inputs (5)
    - 5 Zahlen in zufälliger Reihenfolge
Lösungsidee:
    - Bubbelsort, da die Laufzeit bei einer Inputgröße von 5 keine relevante Rolle spielt
    Boxen:
        - 5 Outputboxen
        - Box "Tausch"
        - Box "Schritte" -> Zählt wie oft ich Tauschen muss
        - Box "Boxnummer"
    How-To (hier habe ich eine Art Pseudocode probiert):
        - Lege 0 in "Tausch"
        - Solange "Schritte" an Punkt x nicht 0 ist wiederhole:
            - Lege 0 in "Schritte"
            - Lege 1 in "Boxnummer" und wiederhole bis in Boxnummer 4 liegt:
                - Wenn der Inhalt von Box (Boxnummer) > Box (Boxnummer +1):
                    - Lege den Inhalt von Box (Boxnummer) in "Tausch"
                    - Lege den Inhalt von Box (Boxnummer + 1) in Box (Boxnummer)
                    - Lege den Inhalt von "Tausch" in Box (Boxnummer + 1)
                    - Zähle 1 zu "Schritte" dazu
        - Punkt x
        - Lege den Inhalt der jeweiligen Box in ihre Outputbox (Eingabebox 1 -> Outputbox 1)
c)
Bubble Sort:
    Big-O-Notation: n^2
    Omega-Notation: n         
*/
#include <stdio.h>
int get_int(char question[]);

int main() {
    //Get numbers
    int numbers[5];
    for (int i = 0; i < 5; i++) {
        numbers[i] = get_int("Nummer: ");
    }
    int swap = 0;
    int steps;
    do {
        steps = 0;
        for (int i = 0; i < 4; i++){
            if (numbers[i] > numbers[i+1]){
                swap = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = swap;
                steps++;
            }
        }
    }while (steps != 0);
    printf("Die richtige Reihenfolge der Zahlen ist:\n");
    for (int i = 0; i < 5; i++){
        printf("%i\n", numbers[i]);
    }
    return 0;
}

//Holt sich die Zahlen
int get_int(char question[]) {
    int a =  0;
    printf("%s", question);
    scanf("%i", &a);
    return a;
}