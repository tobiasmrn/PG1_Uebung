#include <stdio.h>

typedef struct{
    char name[50];
    float gehalt;
    int personalnummer;
}personenkartei;



int main (){
    int auswahl;
    personenkartei *folder;
    auswahl = get_auswahl("Was wollen Sie machen?\n1. Neue Person anlegen\n2. Personenliste ausgeben\n3. Person löschen\n4. Programm beenden\n", &auswahl);

    return 0;
}

int auswahl (char* question){
    int auswahl;
    printf("%s", question);
    scanf("%d", &auswahl);
    switch(auswahl){
        case 1:
            printf("Sie haben gewaehlt, dass Sie eine neue Person anlegen wollen.\n");
            break;
        case 2:
            printf("Sie haben gewaehlt, dass Sie alle Personen ausgeben wollen.\n");
            break;
        case 3:
            printf("Sie haben gewaehlt, dass Sie eine Person loeschen wollen.\n");
            break;
        case 4:
            printf("Sie haben gewaehlt, dass Sie das Programm beenden wollen.\n");
            break;
        default:
            printf("Sie haben eine ungueltige Eingabe gemacht.\n");
            break;
    }
    return auswahl;
}