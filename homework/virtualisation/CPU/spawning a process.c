#include <unistd.h>
#include <time.h>
#include <stdio.h>

const char* program = "/usr/bin/google-chrome";

int main() {
    if (fork() == 0) {
        execv(program, NULL);
    } else {
        while (1) {
            sleep(1);
            printf("i am not vscode \n");
        }
    }
    return 0;
}