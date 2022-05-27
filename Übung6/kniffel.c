#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initD6(void);
int D6(void);
void wurf(int dice_amount, int Wurf[], int Block[], int Speicher[]);
void save (int dice_amount, int Wurf[], int Block[], int Speicher []);
void endsumme (int Speicher[]);

int main (){
    initD6();
    int Wurf[5];
    int Block[5] = {1,1,1,1,1};
    int Speicher[5] ={0};
    int dice_amount = 5;
    printf("Let's go, Kniffel!\n");
    wurf(dice_amount, Wurf, Block, Speicher);
    endsumme(Speicher);
    return 0;
}

void wurf(int dice_amount, int Wurf[], int Block[], int Speicher[]){
    for(int k = 0; k < 2; k++){
        for(int i = 0; i < 5; i++){
            Wurf[i] = D6();
            if(Block[i] != 0){
                int n = i + 1;
                printf("Würfel %i: %i\n", n, Wurf[i]);
            }
        }
        save(dice_amount, Wurf, Block, Speicher);
    }
    for(int k = 0; k < 5; k++){
        Wurf[k]= D6();
        if(Block[k] != 0){
            int n = k + 1;
            printf("Würfel %i: %i\n", n, Wurf[k]);
            Speicher[k] = Wurf[k];
        }
    }

}

void save (int dice_amount, int Wurf[], int Block[], int Speicher []){
    printf("Welchen der Würfel willst du sichern?\n(Würfelzahl angeben oder '9' angeben wenn kein (weiterer) Würfel gesichert werden soll)\n");
    int save_nr = 0;
    static int saved_amount = 0;
    do{
        scanf("%i", &save_nr);
        switch(save_nr){
            case 1:
                if(Block[0] == 0){
                    break;
                }
                Speicher[0] = Wurf [0];
                Block[0] = 0;
                saved_amount++;
                break;
            case 2:
                if(Block[1] == 0){
                    break;
                }
                Speicher[1] = Wurf [1];
                Block[1] = 0;
                saved_amount++;
                break;
            case 3:
                if(Block[2] == 0){
                    break;
                }
                Speicher[2] = Wurf [2];
                Block[2] = 0;
                saved_amount++;
                break;
            case 4:
                if(Block[3] == 0){
                    break;
                }
                Speicher[3] = Wurf [3];
                Block[3] = 0;
                saved_amount++;
                break;
            case 5:
                if(Block[4] == 0){
                    break;
                }
                Speicher[4] = Wurf [4];
                Block[4] = 0;
                saved_amount++;
                break;
            case 9:
                return;
                break;
            default:
                break;
        };
        
    }while((save_nr != 9) || ((save_nr > 5) && (save_nr < 9)) || (save_nr < 1) || (save_nr > 9)|| (saved_amount != 5));
}

void endsumme (int Speicher[]){
    int Summe = 0;
    for(int i = 0; i < 5; i++){
        Summe = Summe + Speicher[i];
    }
    printf("Die Endsumme ist: %i\n", Summe);
}

void initD6(void) {     
    srand((unsigned)time( NULL ) ); 
}

int D6(void) {
    return ((rand()%6)+1); 
}
