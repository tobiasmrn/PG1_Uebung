#include <stdio.h>

int Einlesen(char *Text) {
    int Eingabe;
    printf("%s", Text);
    scanf("%d", &Eingabe);
    fflush(stdin);
    return Eingabe;
}

int MünzenBerechen(int Betrag, int Münzen) {
    return Betrag * 100 / Münzen;
}

void Ausgabe(int Betrag, int Münzen, int Anzahl) {
    printf("Sie bekommen für Ihre %d Euro %d Münzen je %d Cent!\n", Betrag, Anzahl, Münzen);
}

int FehlerBetrag(int Betrag) {
    if (Betrag > 0 && Betrag%5 == 0) {
        return 0;
    }   
    printf("FEHLER: Falscher Betrag!\n");
    return 1;
}

int FehlerMünzen(int Münzen) {
    switch (Münzen) {
    case 5:
    case 10:
    case 20:
    case 50:
    return 0;
    }
    printf("FEHLER: Falsche Münzart!\n");
    return 1;
}

int main() {
    int Betrag;
    int Münzen;
    int Anzahl;
    Betrag = Einlesen("Bitte den Betrag in Euro eingeben: ");
    Münzen = Einlesen("Bitte die gewünschte Münzart (5, 10, 20, 50 Cent) angeben: ");
    //Fehlerüberprüfung entfernt
        Anzahl = MünzenBerechen(Betrag, Münzen);
        Ausgabe(Betrag, Münzen, Anzahl);
    return 0;
}


/* 
Betrag              Münzen              Erwartung               Ergebnis                Fix
0                   0                   ERROR                   0                       if Bedingung --> falls Teiler 0 --> ERROR
0                   10                  0                       0                       -       
-5                  10                  -50                     -50                     Würde durch Fehlerüberprüfung abgefangen werden (oder if Bedingung bei negativer Eingabe)
10                  5                   200                     200                     -
10                  10                  100                     100                     -
10                  20                  50                      50                      -
10                  50                  20                      20                      -         
10                  -10                 -100                    -100                    Würde durch Fehlerüberprüfung abgefangen werden (oder if Bedingung bei negativer Eingabe)
12                  10                  120                     120                     Theoretisch ok, aber Eingabe sollten nur Scheine sein --> Fehlerüberprüfung oder if Bedingung
9999999990          10                  99999999900             -72738096               StackOverflow --> if Bedingung falls Ergebnis negativ
10                  12                  83.3                    83                      Cast auf float, aber da 1>Münzenanzahl>0 nicht möglich --> eigentlich ok
10.1                10                  101                     100                     Runden bei Eingabe da auf int gescannt wird --> passt
10                  10.1                99.0099                 100                     Runden bei Eingabe da auf int gescannt wird --> past

Die meisten Fehler werden durch die Fehlerüberprüfung abgefangen. Alternativ könnte man vor der Rechnung mit if Bedingungen arbeiten, welche die Rechnung nur zulassen, wenn kein kritscher Fall eintrifft --> sonst ERROR-Meldung
*/              