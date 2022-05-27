#include <stdio.h>

void teilaufgabe_a();
void teilaufgabe_b();
void teilaufgabe_c();
void teilaufgabe_d();
void teilaufgabe_e();

int main() {
    char input = 'x';
    printf("Welche Teilaufgabe soll bearbeitet werden?(Möglichkeiten: a, b, c, d, e)\n");
    scanf("%c", &input);
    switch(input){
        case 'a':
            teilaufgabe_a(); 
            break;
        case 'b':
            teilaufgabe_b();
            break;
        case 'c':
            teilaufgabe_c();
            break;
        case 'd':
            teilaufgabe_d();
            break;
        case 'e':
            teilaufgabe_e();
            break;
        default:
            printf("ERROR: Nicht akzeptierte Eingabe. Das Programm wird beenden!\n");
            return 1;
            break;
    }
    return 0;
}

void teilaufgabe_a() {
    float x = 0;
    float a = 0;
    float b = 0;
    float c = 0;
    float d = 0;
    printf("Wir beginnen mit der Unteraufgabe i). Bitte geben Sie einen Wert für x ein (float): ");
    scanf("%f", &x);
    float ergebnis_i = (2 * x * x) + (3 * x) + 17;
    printf("\nDas Ergebnis ist %f.\nWir fahren mit der Unteraufgabe ii) fort. Bitte geben Sie die Werte für a, b, c und d ein (float)(nach jeder Zahl mit ENTER bestaetigen):\n", ergebnis_i);
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    scanf("%f", &d);
    float ergebnis_ii = (a - 3) / (b + 2 * (c / ((d + 3) * (d + 3) * (d + 3))));
    printf("\nDas Ergebnis ist %f\n", ergebnis_ii);
    return;
}

void teilaufgabe_b() {
    int vor_negativ = 0;
    int negativ = 1;
    unsigned int u_vor_negativ = 0;
    unsigned int u_negativ = 1;
    short vor_negativ_s = 0;
    short negativ_s = 1;
    unsigned short u_vor_negativ_s = 0;
    unsigned short u_negativ_s = 1;
    long vor_negativ_l = 0;
    long negativ_l = 1;
    unsigned long u_vor_negativ_l = 0;
    unsigned long u_negativ_l = 1;
    int variante = 0;
    printf("Für welchen Datentyp wollen Sie testen? 0 = int || 1 = short || 2 = long \n(Bitte beachten Sie, dass es beim Test auf long zu sehr langen Wartezeiten kommen kann!)\n");
    scanf("%i", &variante);
    switch (variante){
        case 0:
            do {
                vor_negativ++;
                negativ++;
            } while(negativ > 0);
            printf("Für int ist die höchste abspeicherbare Zahl: %i\n", vor_negativ);
            do {
                u_vor_negativ++;
                u_negativ++;
            } while(u_negativ > 0);
            printf("Für unsigned int ist die höchste abspeicherbare Zahl: %u\n", u_vor_negativ);
            break;

        case 1:
            do {
                vor_negativ_s++;
                negativ_s++;
            } while(negativ_s > 0);
            printf("Für short ist die höchste abspeicherbare Zahl: %i\n", vor_negativ_s);
            do {
                u_vor_negativ_s++;
                u_negativ_s++;
            } while(u_negativ_s > 0);
            printf("Für unsigned short ist die höchste abspeicherbare Zahl: %u\n", u_vor_negativ_s);
            break;

        case 2:
            do {
                vor_negativ_l++;
                negativ_l++;
            } while(negativ_l > 0);
            printf("Für long ist die höchste abspeicherbare Zahl: %li\n", vor_negativ_l);
            do {
                u_vor_negativ_l++;
                u_negativ_l++;
            } while(u_negativ_l > 0);
            printf("Für unsigned short ist die höchste abspeicherbare Zahl: %lu\n", u_vor_negativ_l);
            break;
        
        default:
            printf("ERROR\n");
            break;
    }
    return;
}

void teilaufgabe_c() {
    printf("In dieser Teilaufgabe versuchen wir die Ganzzahl 5 zuerst durch eine Konstante 0 zu teilen und anschließend durch eine Variable zu teilen, deren Wert 0 entspricht. Erwartet wird, dass ein ERROR fliegt.\n");
    int dividend = 5;
    int ergebnis_1 = dividend / 0;
    printf("Das Ergebnis der ersten Rechnung ist: %i\n", ergebnis_1);
    int divisor = 0;
    int ergebnis_2 = dividend / divisor;
    printf("Das Ergebnis der zweiten Rechnung ist: %i\n", ergebnis_2);
    return;
}

void teilaufgabe_d() {
    printf("In dieser Teilaufgabe versuchen wir die Gleitkommazahl 8.0 zuerst durch eine Konstante 0 zu teilen und anschließend durch eine Variable zu teilen, deren Wert 0 entspricht. Erwartet wird, dass ein ERROR fliegt.\n");
    float dividend = 8.0;
    float ergebnis_1 = dividend / 0.0;
    printf("Das Ergebnis der ersten Rechnung ist: %f\n", ergebnis_1);
    float divisor = 0.0;
    float ergebnis_2 = dividend / divisor;
    printf("Das Ergebnis der zweiten Rechnung ist: %f\n", ergebnis_2);
    return;
}

void teilaufgabe_e() {
    printf("Das Ergebnis der Rechnung aus Google ist: 14.8131852\n");
    float f_ergebnis = 4.4444 * 3.333;
    printf("Das Ergebnis mit dem Datentyp float ist: %.20f\n", f_ergebnis);
    double d_ergebnis = 4.4444 * 3.333;
    printf("Das Ergebnis mit dem Datentyp double ist: %.20f\n", d_ergebnis);
    return;
}