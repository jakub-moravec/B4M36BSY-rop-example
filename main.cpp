#undef _FORTIFY_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

using namespace std;

void vulnerable_function(char* string) {
    char buf[16];
    strcpy(buf, string);
    return;
}

int main(int argc, char** argv) {
    vulnerable_function(argv[1]);
    return 0;
}