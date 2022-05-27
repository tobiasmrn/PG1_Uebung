/*
2 a)

Der Übertrag ist für die erste Spalte (Von hinten angefangen) entspricht 0.
Wiederhole 2 mal
    Bilde eine Summer aus den einzelnen Bits in der aktuellen Spalte und dem Übertrag
        Wenn Summe == 0 
            Dann setze das Ergebnis für diese Spalte auf 0 und gehe zur nächsten Spalte
        Wenn Summe == 1
            Dann setze den Übertrag auf 0, das Ergebnis für diese Spalte auf 1 und gehe zur nächsten Spalte
        Wenn Summe == 2
            Dann setze den Übertrag auf 1, das Ergebnis für diese Spalte aus 0 und gehe zur nächsten Spalte 
        Wenn Summe == 3
            Dann setze den Übertrag auf 1, das Ergebnis für diese Spalte aus 1 und gehe zur nächsten Spalte
    
Das Ergbnis ist nun der Übertrag und die darauf folgenden Spalten
*/

#include <stdio.h> 

int main() {
    int opp1 [2];
    int opp2 [2];
    int erg [2];
    int uebertrag = 0;
    //Erste "Zahl" abfragen
    printf("Geb deine erste 2-Bit-Zahl (einzelne Bits von hinten angefangen) ein (nach jedem Bit mit 'ENTER' bestätigen) :)\n");
    for (int i = 0; i < 2; i++){
        do{
            scanf("%i", &opp1[i]);
            if(opp1[i] > 1 || opp1[i] < 0){
                printf("Ey yo! Bits sind Nullen und Einsen und nicht was auch immer das gerade war\n");
            }
        } while (opp1[i] > 1 || opp1[i] < 0);
    }
    //Zweite "Zahl" abfragen
    printf("Geb deine zweite 2-Bit-Zahl (einzelne Bits von hinten angefangen) ein (nach jedem Bit mit 'ENTER' bestätigen) :)\n");
    for (int i = 0; i < 2; i++){
         do{
            scanf("%i", &opp2[i]);
            if(opp1[i] > 1 || opp1[i] < 0){
                printf("Ey yo! Bits sind Nullen und Einsen und nicht was auch immer das gerade war\n");
            }
        } while (opp2[i] > 1 || opp2[i] < 0);
    }
    //Rechenmechanismus
    for (int i = 0; i < 2; i ++){
        int summe = opp1[i] + opp2[i] + uebertrag;
        switch (summe) {
            case 0: 
                erg[i] = summe;
                break;
            case 1: 
                uebertrag = 0;
                erg[i] = 1;
                break;
            case 2: 
                uebertrag = 1;
                erg[i] = 0;
                break;
            case 3:
                uebertrag = 1;
                erg[i] = 1;
                break;
            default:
                break;
        }
    }
    //Ergebnis
    printf("Das Ergebnis ist %i%i%i\n",uebertrag, erg[1], erg[0]);
    return 0;
}