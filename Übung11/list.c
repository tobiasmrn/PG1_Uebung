#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
    struct person* prev;
    char name[50];
    float gehalt;
    int personalnummer;
    struct person* next;
}person;

int get_auswahl (char* question);
void person_anlegen(person* tail);
void print_all(person* head);
void delete_person(person* head);

int main(){
    person anker1;
    person anker2;
    anker1.prev = NULL;
    anker1.next = &anker2;
    anker2.prev = &anker1;
    anker2.next = NULL;
    person* head = &anker1;
    person* tail = &anker2;
    while(1){
        int auswahl = get_auswahl("\nWas wollen Sie machen?\n1. Neue Person anlegen\n2. Personenliste ausgeben\n3. Person löschen\n4. Programm beenden\n");
        switch(auswahl){
            case 1:
                // Person anlegen
                person_anlegen(tail);
                break;
            case 2:
                // Personenliste ausgeben
                print_all(head);
                break;
            case 3:
                // Person löschen
                printf("Zur Hilfe wird die Personenliste ausgegeben\n");
                print_all(head);
                delete_person(head);
                break;
            case 4:
                // Programm beenden
                printf("\nProgramm beendet!\n");
                return 0;
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
    scanf("%d", &auswahl);
    return auswahl;
}

void person_anlegen(person* tail){
    person* new_person = (person*)malloc(sizeof(person));
    printf("\nBitte geben Sie den Namen ein: ");
    scanf("%50s", &new_person->name);
    printf("Bitte geben Sie das Gehalt ein: ");
    scanf("%f", &new_person->gehalt);
    printf("Bitte geben Sie die Personalnummer ein: ");
    scanf("%d", &new_person->personalnummer);
    new_person->prev = tail->prev;
    new_person->next = tail;
    tail->prev->next = new_person;
    tail->prev = new_person;
    printf("\nPerson angelegt!\n");
                
}

void print_all(person* head){
    person* current = head;
    if(current->prev == NULL){
        current = current->next;
    }
    while(current->next != NULL && current->prev != NULL){
        printf("\nName: %s\n", current->name);
        printf("Gehalt: %.2f Euro\n", current->gehalt);
        printf("Personalnummer: %d\n", current->personalnummer);
        current = current->next;
    }
}

void delete_person(person* head){
    int personalnummer;
    printf("\nBitte geben Sie die Personalnummer ein: ");
    scanf("%d", &personalnummer);
    person* current = head;
        while(current != NULL){
            if(current->personalnummer == personalnummer){
                current->prev->next = current->next;
                current->next->prev = current->prev;
                free(current);
            }
            current = current->next;
        }
    printf("\nPerson gelöscht!\n");
}


