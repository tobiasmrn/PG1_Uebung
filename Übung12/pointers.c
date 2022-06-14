#include <stdio.h>

void Zahl_ausgeben2(int **Zahl) {
    printf("Zahl: %d\n", **Zahl);
}
void Zahl_ausgeben1(int *Zahl) {
    //Nur ein '&' das Zahl in dieser Funktion bereits als Pointer definiert ist.
    Zahl_ausgeben2(&Zahl);
}
int main() {
    int Zahl = 5;
    Zahl_ausgeben1(&Zahl);
    return 0;
}