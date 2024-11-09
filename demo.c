#!/bin/tcc -run
#ifndef rtch
#define rtch
// real time c helper start
#include <stdio.h>
#include <stdlib.h>

void rtch_startfile(char* filename) {
    char* cmd = (char*)malloc(128);
    sprintf(cmd, "tcc -run %s", filename);
    system(cmd);
}
// real time c helper end
#endif

#include <string.h>    
#include <unistd.h> 

void serpinsky_proccessing(char* state) {
    char* old_state = malloc(25);
    for (int i = 0; i < 25; i++) {
        old_state[i] = state[i];
    }
    for (int i = 1; i < 25; i++) {
        if (old_state[i-1]) {
            state[i] ^= 1;
        }
    }
    free(old_state);
}

int serpinsky() {
    printf("123");
    char* k = malloc(25);
    k[0] = 1;
    
    char* screen = malloc(80*25+1);
    memset(screen, ' ', 80*25+1);
    while (1) {
        serpinsky_proccessing(k);
        for (int j = 0; j < 25; j++) {
            screen[j*80] = k[25-j] ? '#' : '-';
            for (int i = 79; i > 0; i--) {
                screen[i+j*80] = screen[i-1+j*80];
            }
        }
        int i = 0;
        printf("\x1b[d\x1b[H");
        for (int c = 0; c < 80*25; c++) {
            if (c % 80 == 79) {
                putchar('\n');
            } 
            else {
                putchar(screen[c]);
            }
        }
        usleep(30000);
    }
    free(k);
    free(screen);
}

int main() {
    printf("Hello, to rtc demo program!\n");
    for (;;) {
        printf("select option(0 - run rtc program, 1 - serpinsky):\n>>>");
        char* option = malloc(10);
        scanf("%s", option);
        if (option[0] == '0') {
            free(option);
            option = malloc(50);
            printf("program file name:\n>>>");
            scanf("%s", option);
            rtch_startfile(option);
        }
        else if (option[0] == '1') {
            free(option);
            serpinsky();
        }
        if (option != NULL) {
            free(option);
        }
    }
}