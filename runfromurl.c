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

int main() {
    printf("hello, to runfromurl\n");
    for (;;) {
        printf("write url to download:\n>>>");
        char* url = malloc(256);
        scanf("%s", url);
        char* cmd = (char*)malloc(512);
        sprintf(cmd, "curl %s -o /tmp/downloaded2.c", url);
        system(cmd);
        rtch_startfile("/tmp/downloaded2.c");
    }
}