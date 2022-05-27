#include <stdio.h>

int filler (int numbers[], int array_size);
double adder (int numbers[], int array_size, int save);
int min (int numbers[], int array_size);
int tausch(int* a, int* b);
int sorter(int numbers[], int array_size);
int sorted(int numbers[], int array_size);
 
int main()
{
    int numbers[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int array_size = sizeof(numbers) / sizeof(numbers[0]);
    filler(numbers, array_size);
    sorter(numbers, array_size);
    printf("Das Maximum ist: %i!\nDas Minimum ist: %i!\n", numbers[9], numbers[min(numbers, array_size)]);
    printf("Der Durchschnitt der von dir eingegeben Zahlen ist: %.2lf!\n", adder(numbers, array_size, min(numbers, array_size)));
    printf("Deine Zahlen sortiert: \n");
    sorted(numbers, array_size);
    return 0;
}

int filler (int numbers[], int array_size){
    printf("Bitte gib 10 Zahlen ein die größer als 0 sind!\n");
    for (int i = 0; i < array_size; i++){
        scanf("%i", &numbers[i]);
        if(numbers[i] < 0){
            numbers[i] = -1;
            printf("Tja Sportsfreund, mit der Eingabe hast du dir dein Recht versaut weitere Eingaben zu tätigen!\n");
            return 1;
        }
    }
    return 0;
}

int min (int numbers[], int array_size){
    int i = 0;
    for (i = 0; i < array_size; i++){
       if(numbers[i] > -1){
           break;
       }
    } 
    return i;
}

double adder (int numbers[], int array_size, int save){
    int sum = 0;
    for (int i = 0; i < array_size; i++){
        if(numbers[i] > -1){
            sum += numbers[i];
        }
    }
    return (double)sum / (array_size - save);
}

int tausch(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}
 
int sorter(int numbers[], int array_size){
    for (int i = 0; i < array_size - 1; i++){
        for (int j = 0; j < array_size - i - 1; j++){
            if (numbers[j] > numbers[j+1]){
                tausch(&numbers[j], &numbers[j + 1]);
            }
        }
    }
    return 0;
}
 
int sorted(int numbers[], int array_size){
    for (int i = 0; i < array_size; i++){
        if (numbers[i] > -1){
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");
    return 0;
}