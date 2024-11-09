// just put it in you c file
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