/*
This should be able to measure the time delay of 
a single call to gettimeofday
*/

#include <sys/time.h>
#include <stdio.h>

struct timeval start, end;
int duration;

int main() {
    gettimeofday(&start, NULL);
    gettimeofday(&end, NULL);
    duration =
        end.tv_sec * 1000000 + end.tv_usec
        - start.tv_sec * 1000000 - start.tv_usec;
    printf("%d\n", duration);
    return 0;
}

/*
RESULTS:
The overhead is 0 microseconds. No overhead.
*/