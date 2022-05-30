#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[50];
    float gehalt;
    int personalnummer;
}person;

person* add_person();
int print_all();
int delete_person();
int get_auswahl(char* question);

int main (){
    int auswahl;
    person **personenkartei;
    auswahl = get_auswahl("Was wollen Sie machen?\n1. Neue Person anlegen\n2. Personenliste ausgeben\n3. Person löschen\n4. Programm beenden\n");
    switch(auswahl){
        case 1:
            add_person();
            break;
        case 2:
            print_all();
            break;
        case 3:
            delete_person();
            break;
        default:
            printf("Unerwarteter Fehler!\n");
            exit(1);
            break;
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

person* add_person(){
    person *new_person;
    new_person = (person*) malloc(sizeof(person));
    printf("Bitte geben Sie den Namen der neuen Person ein: ");
    scanf("%s", &new_person->name);
    printf("Bitte geben Sie das Gehalt der neuen Person ein: ");
    scanf("%f", &new_person->gehalt);
    printf("Bitte geben Sie die Personalnummer der neuen Person ein: ");
    scanf("%d", &new_person->personalnummer);
    printf("Die neue Person wurde angelegt.\n");
    printf("%s\n", new_person->name);
    return new_person;
}

int print_all(){
    return 0;
}

int delete_person(){
    return 0;
}