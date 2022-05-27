/*
a)
Gegeben:
    - Fest Anzahl an Inputs (5)
    - 5 Zahlen in zufälliger Reihenfolge
Lösungsidee:
    Boxen:
        - Merkbox für "Schritte" "(i von 4)
        - Merkbox für "Boxzahl"
        - Zwei Vergleichsboxen -> aktuell kleinste Variable (akv)/ Vergleichswert (vw)
        - Eine Outputbox
    How-To:
        - Lege 4 in die Merkbox für die Schritte
        - Lege den Inhalt von Box 1 in Box "akv"
        - Lege den Inhalt aus Box 2 in Box "vw"
        - Lege 2 in Box "Boxzahl"
        - Wiederhole solange bis in der Schritte-Merkbox 0 sind:
            - Vergleiche "akv" und "vw" -> wenn "vw" > "akv" dann lege den Inhalt aus "vw" in "akv"
            - Addiere zum Inhalt von Box "Boxzahl" 1 dazu und lege den Inhalt aus dieser Box in "vw"
            - Ziehe eins von Box "Schritte" ab
        - Lege den Inhalt von Box "akv" in die Outputbox

d)
Ich brauche immer 4 Durchgänge zum Vergleichen
Theta-Notation: n
*/
#include <stdio.h>

int get_int(char question[]);

int main() {
    //Get numbers 1=5
    int numbers[5];
    for (int i = 0; i < 5; i++) {
        numbers[i] = get_int("Nummer: ");
    }
    int akv = numbers[0];
    int vw = numbers[1];
    /*Gehe das Array durch und checke, ob die aktuelle Zahl kleiner ist als die bisher bekannte kleinste Zahl
    Ist dem so, dann setzte akv auf vw
    Wiederhole das ganze 4x
    */
    for (int i = 0; i < 4; i++) {
        if (vw < akv) {
            akv = vw;
        }
        vw = numbers[i+2];
    }
    printf("Die kleinste Zahl ist: %i\n", akv);
    return 0;
}

//Holt sich die Zahlen
int get_int(char question[]) {
    int a =  0;
    printf("%s", question);
    scanf("%i", &a);
    return a;
}