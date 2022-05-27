#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<ctype.h>

#define LENGTH 251

int get_input (char *question, char *input);
char* cutter(char *input);
int w_s_check(char *input);
int get_end(char *input);
char* strrev (char *input);
int is_palindrom(char *input);

int main(){
    char input[LENGTH];
    get_input("Ihre Eingabe wird erwartet: \n", input);
    /*
    Input Test:
    printf("Eingabentest: %s\n", input);
    */
    printf("Der umgekehrte String lautet: %s\n", strrev(input));
    cutter(input);
    int check = w_s_check(input);
    if(!check){
        if(!is_palindrom(input)){
            printf("Palindrom!\n");
        }
        else{
            printf("Kein Palindrom!\n");
        }
    }
    return 0;
}

int get_input (char *question, char *input){
    printf("%s", question);
    printf("(Bitte beachten Sie, dass Ihre Eingabe maximal %i Zeichen beinhalten darf!\n", LENGTH -1);
    fgets(input, LENGTH, stdin);
    return 0;
}

int w_s_check(char *input){
    int check = 0;
    int end = 0;
    while(*(input + end) != '\n'){
        if(*(input + end) == ' '){
            check = 1;
        }
        end++;
    }
    return check;
}

int get_end(char *input){
    int end = 0;
    while(*(input + end) != '\n'){
        end++;
    }
    //printf("End: %i", end);
    return end;
}

char* strrev (char *input){
    int end = get_end(input);
    char swap;
    for(int i = 0; i < (end/2); i++){
        swap = *(input + i);
        *(input + i) = *(input + end - i -1);
        *(input + end - i -1) = swap;
    }
    return input;
}

int is_palindrom(char *input){
    int end = get_end(input);
    char rev[LENGTH];
    strncpy(rev, input, end + 2);//das plus 2 habe ich über Try and Error herausgefunden, da bin ich mir nicht ganz sicher
    strrev(input);
    //printf("Rev: %s\nOrg: %s\n", rev, input);
    int var = strncasecmp(input, rev, end);
    //printf("Testvar: %i\n", var);
    return var;
}

char* cutter(char *input){
    printf("\n\nCHECK!\n\n");
    strrev(input);
    int end = get_end(input);
    int swap = 0;
    for(int i = 0; i < end; i++){
        if(isalpha(*(input + i))){
            *(input + swap) = *(input + i);
            swap++;
        }
    }
    *(input + swap) = '\0';
    printf("Cuttted: %s", input);
    return input;
}
