#include <stdio.h>

void on_off(char ZUSTAND);
void r_b_print(char ZUSTAND);
char l_change (char ZUSTAND);
char m_change (char ZUSTAND);
char g_flip (char ZUSTAND);


int main() {
    char ZUSTAND = 0xC5;
    on_off(ZUSTAND);
    r_b_print(ZUSTAND);
    ZUSTAND = l_change(ZUSTAND);
    ZUSTAND = m_change(ZUSTAND);
    ZUSTAND = g_flip(ZUSTAND);
    printf("0x%X\n", ZUSTAND & 0xFF);
    return 0;

}

void on_off (char ZUSTAND){
    int on_off_mask = 0x80;
    int on_off = ZUSTAND & on_off_mask;
    if(on_off == 0x80) {
        printf("on\n");
    } else {
        printf("off\n");
    }
    return;
}

void r_b_print (char ZUSTAND){
    int r_mask = 0x40;
    int b_mask = 0x10;
    int r = ZUSTAND & r_mask;
    int b = ZUSTAND & b_mask;
    if(r == 0x40) {
        printf("R = 1\n");
    } else {
        printf("R = 0\n");
    }
    if(b == 0x10) {
        printf("B = 1\n");
    } else {
        printf("B = 0\n");
    }
    return;
}

char l_change (char ZUSTAND){
    char l_mask = 0xF3;
    char l_change = ZUSTAND & l_mask;
    return l_change;
}

char m_change (char ZUSTAND){
    char m_mask = 0x3;
    char m_change = ZUSTAND | m_mask;
    return m_change;
}

char g_flip(char ZUSTAND){
    char g_mask = 0x20;
    char g_flip = ZUSTAND ^ g_mask;
    return g_flip;
}