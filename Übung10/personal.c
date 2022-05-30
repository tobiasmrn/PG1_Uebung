#include <stdio.h>
#include <stdlib.h>



typedef struct{
    char name[50];
    float gehalt;
    int personalnummer;
}personenkartei;



int main (){
    int auswahl;
    personenkartei *folder [1];
    auswahl = get_auswahl("Was wollen Sie machen?\n1. Neue Person anlegen\n2. Personenliste ausgeben\n3. Person löschen\n4. Programm beenden\n", &auswahl);
    switch(auswahl){
        case 1:
    }
    return 0;
}

int get_auswahl (char* question){
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
            exit(0);
            break;
        default:
            printf("Sie haben eine ungueltige Eingabe gemacht.\n");
            exit(1);
            break;
    }
    return auswahl;
}

int add_person(){
    return 0;
}

int print_all(){
    return 0;
}

int delete_person(){
    return 0;
}