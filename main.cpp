#undef _FORTIFY_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>

using namespace std;

void vulnerable_function() {
    char buf[128];
    read(STDIN_FILENO, buf,256);
}

int main(int argc, char** argv) {
    cout << system ("/bin/sh");
    vulnerable_function();
    write(STDOUT_FILENO, "Hello, World\n", 13);
}