#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    person* prev;
    char name[50];
    float gehalt;
    int personalnummer;
    person* next;
}person;

int main(){
    char name;
    float gehalt;
    int personalnummer;
    return 0;
}

int init_list (){
    person* head = (person*)malloc(sizeof(person));
    person* tail = (person*)malloc(sizeof(person));
    head->prev = NULL;
    head->next = tail;
    tail->prev = head;
    tail->next = NULL;
    return 0;
}

int create_person (person* head, person* tail, char* name, float gehalt, int personalnummer){
    person* new_person = (person*)malloc(sizeof(person));
    new_person->prev = tail->prev;
    new_person->next = tail;
    tail->prev->next = new_person;
    tail->prev = new_person;
    strcpy(new_person->name, name);
    new_person->gehalt = gehalt;
    new_person->personalnummer = personalnummer;
    return 0;
}

int get_data (char* name, float* gehalt, int* personalnummer){
    printf("Name: ");
    scanf("%s", name);
    printf("Gehalt: ");
    scanf("%f", gehalt);
    printf("Personalnummer: ");
    scanf("%d", personalnummer);
    return 0;
}
