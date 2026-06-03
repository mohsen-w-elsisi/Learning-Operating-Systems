#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

struct timeval start, end;
int elapsedTime;

int main() {
    gettimeofday(&start, NULL);
    getpid(); // just a syscall with no I/O
    gettimeofday(&end, NULL);
    elapsedTime = 
        end.tv_sec * 1000000 + end.tv_usec 
        - start.tv_sec * 1000000 - start.tv_usec;
    printf("%d\n", elapsedTime);
    return 0;
}

/*
RESULTS:
getpid() takes 5 secs commonly. It may go down to 4 secs and up to 17 secs or 
even 28, but 5 secs is the mode. This is longer than I expected. Both the book
and the internet claim it should be an order of magnitude less than.
*/