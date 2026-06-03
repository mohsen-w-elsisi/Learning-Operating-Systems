/*
In this code, I use the RDTSC instruction to measure the number of CPU cycles taken by the getpid() syscall. The RDTSC instruction reads the time-stamp counter, which is a 64-bit register that counts the number of cycles since reset. By taking the difference between the start and end values, we can calculate the number
of cycles taken by the syscall, and hence the time.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <x86intrin.h>

unsigned long long start, end;
double duration;
long clockRate;

void getClockRate();

int main() {
    getClockRate();
    start = __rdtsc();
    getpid();
    end = __rdtsc();
    duration = ((double) (end - start) / clockRate) * 1000000; 

    printf("Start: %llu \n", start);
    printf("End: %llu \n", end);
    printf("Duration: %lf \n", duration);

    return 0;
}

void getClockRate() {
    FILE* file = fopen("/sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq", "r");

    char line[16];
    fgets(line, sizeof(line), file);
    clockRate = atol(line) * 1000; // convert from kHz to Hz
    printf("Clock Rate: %ld MHz \n", clockRate);

    fclose(file);
}

/*
RESULTS:
This method is no doubt more accurate. It however assumes the 
CPU is running at mac frequencey. The output was on ~2 microseconds,
which is not submicrosecond speeds, but that may be caused by 
process schedualing and the such.
*/
