#include <stdio.h>

int getEinkommen (char question[]);
int steuer_calc(int einkommen);

int main () {
    int einkommen = getEinkommen("Wie viel haben Sie verdient: \n");
    steuer_calc(einkommen);
    return 0;
}

int getEinkommen (char question []){
    int einkommen = 0;
    printf("%s", question);
    do{
        scanf("%d", &einkommen);
        if(einkommen <= 0){
            printf("Schwierige Eingabe, das probieren wir nochmal!\n");
        }
    } while (einkommen <= 0);
    return einkommen;
}

int steuer_calc (int einkommen){
    if(einkommen < 10001){
        printf("Geringverdiener müssen keine Steuern zahlen!\n");
        return 0;
    }
    einkommen -= 10000;
    double steuersatz = 0.05;
    double steuer = 0;
    while(einkommen > 199){
        steuer = steuer + 200 * steuersatz;
        if(steuersatz < 0.5){
            steuersatz += 0.002;
        }
        einkommen -= 200;
    }
    if(einkommen > 0 && einkommen < 200){
        steuer = steuer + einkommen * steuersatz;
    }
    printf("Dat macht dann %.2f Euro an Steuern!\n", steuer);
    return 0;
}
