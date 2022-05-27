#include <stdio.h>
#define MAX_STRING_SIZE 15
#define NUMBER_OF_STRING 7

int get_input(char question[], int lower_end, int upper_end, int relation);
int year_check(int input, int relation, int lower_end, int upper_end);
int month_check(int input, int relation, int lower_end, int upper_end);
int day_check(int input, int relation, int lower_end, int upper_end);
int rechner(int day, int month, int year);

int main(){
    int day_realtion = 0;
    int year_realtion = 0;
    int day = get_input("Bitte geben Sie den Tag an: \n", 0, 32, day_realtion);
    int month = get_input("Bitte geben Sie den Monat an: \n", 0, 13, day);
    if(day == 29 && month == 2){
        year_realtion = 1;
    }
    int year = get_input("Bitte geben Sie das Jahr an: \n", 1581, 900000000, year_realtion);
    char days[NUMBER_OF_STRING][MAX_STRING_SIZE] = {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};
    int result = rechner(day, month, year);
    printf("Der %i.%i.%i ist ein %s.\n", day, month, year, days[result]);
    return 0;
}

int get_input(char question[], int lower_end, int upper_end, int relation) {
    printf("%s", question);
    int input;
    int checker = 0;
    do{
        scanf("%d", &input);
        if(lower_end == 1581){
            checker = year_check(input, relation,lower_end, upper_end);
        }
        if(upper_end == 13){
            checker = month_check(input, relation,lower_end, upper_end);
        }
        if(upper_end == 32){
            checker = day_check(input, relation, lower_end, upper_end);
        }
    } while (checker == 0);
    return input;
}

int year_check(int input, int relation, int lower_end, int upper_end){
    int checker = 1;
    if(input > lower_end && input < upper_end){
        checker = 1;
    }
    else{
        checker = 0;
        printf("Jahr nicht möglich!\n");
    }
    if (checker == 0){
        return checker;
    }
    if(relation == 1){
        //Checkt ob es sich um ein Schaltjahr handelt
        checker = 0;
        if((input % 4 == 0) && (input % 100 != 0)){
                checker = 1;
        }
        if((input % 400 != 0) && (input % 100 == 0)){
            checker = 0;
        }
            if((input % 400 == 0)){    
            checker = 1;
        }
        if(checker == 0){
        printf("In diesem Jahr gibt es keinen 29. Februar.\n");
        }
    }
    return checker;
}

int month_check(int input, int relation, int lower_end, int upper_end){
    int checker = 1;
    if(input > lower_end && input < upper_end){
        checker = 1;
    }
    else{
        checker = 0;
        printf("Monat nicht möglich!\n");
    }
    if (checker == 0){
        return checker;
    }
    if(input == 2){
        if(relation > 29){
            checker = 0;
        }
    }
    if(relation == 31){
            switch (input){
                case 2:
                    checker = 0;
                    break;
                case 4:
                    checker = 0;
                    break;
                case 6:
                    checker = 0;
                    break;
                case 9:
                    checker = 0;
                    break;
                case 11:
                    checker = 0;
                    break;
                default:
                    break;
            };
    }
    if(checker == 0){
        printf("Tagesanzahl stimmt nicht mit dem Monat überein!\n");
    }
    return checker;
}

int day_check(int input, int relation, int lower_end, int upper_end){
    int checker;
    if(input > lower_end && input < upper_end){
        checker = 1;
    }
    else{
        checker = 0;
        printf("Tag nicht möglich!\n");
    }
    return checker;
}

int rechner(int day, int month, int year){
    if(month <= 2){
        month += 12; 
        year -= 1;
    }
    int result = (day + 2 * month + (3 * month + 3) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
    return result;
}

/*
TestTabelle

Eingabe         Erwartungswert                          Ergebnis
20.4.2022       Mittwoch                                Mittwoch
22.7.2002       Montag                                  Montag  
1.1.1200        Jahr nicht möglich!                     Jahr nicht möglich!
29.2.2022       Tag existiert nicht!                    In diesem Jahr gibt es keinen 29. Februar.
31.6.2022       Tag und Monat nicht kompatibel!         Tagesanzahl stimmt nicht mit dem Monat überein!
40.5.2022       Tag nicht möglich!                      Tag nicht möglich!
15.40.2022      Monat nicht möglich!                    Monat nicht möglich!
29.2.2024       Donnerstag                              Donnerstag
01.01.2022      Samstag                                 Samstag
*/