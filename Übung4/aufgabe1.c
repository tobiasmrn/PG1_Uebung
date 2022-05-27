#include <stdio.h>
#include <math.h>

int get_input(char question[]);
int input_error_check(int eingabe);
double calc_price(int input);
double discount(double discount, double unit_price, int quantity);
double round_price(double original_price);

int main() {
    int input = get_input("Wie viele Zahnräder wollen Sie kaufen?\n");
    double original_price = calc_price(input);
    double price = round_price(original_price);
    printf("Die Zahnräder gehören dir für %.2lf Euronen!\n", price);
    return 0;
}

int get_input(char question[]) {
    printf("%s", question);
    int input;
    int checker = 0;
    do{
        scanf("%d", &input);
        checker = input_error_check(input);
    } while (checker == 0);
    return input;
}

int input_error_check(int eingabe) {
    int checker = 1;
    if(eingabe < 1) { //Möglichkeit für einen Errorcheck auf Float?
        checker = 0;
        printf("ERRORCODE 001\nDie Eingabe war nicht erfolgreich. Bitte versuchen Sie es erneut!\n");
    }
    return checker;
}

double calc_price(int input) {
    double unit_price = 0.8;
    int quantity = input;
    double original_price = 0.0;
    if (0 < quantity && quantity < 10){
        original_price = discount(0.0, unit_price, quantity);
    }
    if (9 < quantity && quantity< 50){
        original_price = discount(0.03, unit_price, quantity);
    }
    if (49 < quantity && quantity < 100){
        original_price = discount(0.05, unit_price, quantity);
    }
    if (99 < quantity){
        original_price = discount(0.08, unit_price, quantity);
    }
    return original_price;
}

double discount(double discount, double unit_price, int quantity){
    double fixed_price = unit_price * quantity;
    double original_price = fixed_price - (fixed_price * discount);
    return original_price;
}

double round_price(double original_price){
    original_price = original_price * 10;
    double final_price = round(original_price);
    final_price = final_price / 10;
    return final_price;
}

/*
TestTabelle

Stückzahl           Erwartungswert          Ergebnis            
0                   0                       ERROR
2                   1.60                    1.60
3                   2.40                    2.40    
9                   7.20                    7.20
10                  7.80                    7.80
30                  23.30                   23.30
40                  31.00                   31.00
49                  38.00                   38.00
50                  38.00                   38.00
61                  46.40                   46.40
72                  54.70                   54.70
99                  75.20                   75.20
100                 73.60                   73.60
123                 90.50                   90.50
999999999           753999999.30            735999999.30
-1                  ERROR                   ERROR
*/