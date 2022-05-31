#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[50];
    float gehalt;
    int personalnummer;
}person;

person* add_person();
int print_all(person* personenkartei[], int aktuell);
int delete_person(person* personenkartei[], int aktuell);
int get_auswahl(char* question);
int array_fix(person* personenkartei[], int aktuell);

int main (){
    int auswahl;
    int aktuell = 0;
    person *personenkartei[100];
    while(1){
        auswahl = get_auswahl("\nWas wollen Sie machen?\n1. Neue Person anlegen\n2. Personenliste ausgeben\n3. Person löschen\n4. Programm beenden\n");
        switch(auswahl){
            case 1:
                *(personenkartei + aktuell) = add_person();
                aktuell++;
                //printf("Neue Person bei %p\n", (personenkartei + 0));
                break;
            case 2:
                print_all(personenkartei, aktuell);
                break;
            case 3:
                delete_person(personenkartei, aktuell);
                aktuell -= 1;
                break;
            default:
                printf("Unerwarteter Fehler!\n");
                exit(1);
                break;
        }
    }
    return 0;
}

int get_auswahl (char* question){
    int auswahl;
    printf("%s", question);
    //Test
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
    return new_person;
}

int print_all(person* personenkartei[], int aktuell){
    for(int i = 0; i < aktuell; i++){
        if(personenkartei[i] != NULL){
            printf("\nPersonenkarte Nr. %d\n", i + 1);
            printf("Name: %s\n", personenkartei[i]->name);
            printf("Gehalt: %.2f Euro\n", personenkartei[i]->gehalt);
            printf("Personalnummer: %d\n", personenkartei[i]->personalnummer);
        }
    }
    return 0;
}

int delete_person(person* personenkartei[], int aktuell){
    printf("Um das auswählen der zu loeschenden Person zu ermoeglichen, wird die Personenliste ausgegeben.\n");
    print_all(personenkartei, aktuell);
    printf("Bitte geben Sie die Nummer der zu loeschenden Person ein: ");
    int loesch_nr;
    scanf("%d", &loesch_nr);
    loesch_nr -= 1;
    if(personenkartei[loesch_nr] != NULL){
        free(personenkartei[loesch_nr]);
        personenkartei[loesch_nr] = NULL;
        printf("Die Person wurde geloescht.\n");
        array_fix(personenkartei, aktuell);
    }
    else{
        printf("Die Person konnte nicht geloescht werden.\n");
    }
    return 0;
}

int array_fix(person* personenkartei[], int aktuell){
    for(int i = 0; i < aktuell; i++){
        if(personenkartei[i] == NULL){
            for(int j = i; j < aktuell; j++){
                personenkartei[j] = personenkartei[j+1];
            }
        }
    }
    return 0;
}