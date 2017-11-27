#include <stdio.h>
#include <string.h>

void vulnerable(char *argv) {
    char buffer[256];
    strcpy(buffer, argv);

    printf("%s\n",buffer);
}

int main(int argc, char** argv) {
    vulnerable(argv[1]);


    return 0;
}
