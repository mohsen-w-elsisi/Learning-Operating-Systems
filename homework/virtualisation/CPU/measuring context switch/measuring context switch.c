#include <stdio.h>
#include <unistd.h>

const char* programA = "/bin/cat";
const char* programB = "/bin/grep";

const char* argsA[] = { "cat", "file.txt", NULL };
const char* argsB[] = { "grep", "hello", NULL };

int pidA, pidB;

int pipefd[2];

long long start, end;

void createSubprocesses();
void setupPipe();

int main() {
    setupPipe();
    createSubprocesses();
}

void createSubprocesses() {
    if (fork() == 0) {
        
        execv(programA, argsA);
    }
    else {
        pidA = getpid();
        if (fork() == 0) {
            execv(programB, argsB);
        }
        else {
            pidB = getpid();
        }
    }
}

void setupPipe() {
    pipe(pipefd);
}