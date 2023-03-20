#include <stdio.h>
#include <sys/resource.h>
#define errExit(msg) do { perror(msg); exit(1); \
                               } while (0)

int main() {
    struct rlimit lim;
    getrlimit(RLIMIT_STACK, &lim);
    printf("stack size: %ld\n",  lim.rlim_max);

    getrlimit(RLIMIT_NPROC, &lim);
    printf("process limit: %ld\n", lim.rlim_max);

    getrlimit(RLIMIT_NOFILE, &lim);
    printf("max file descriptors: %ld\n", lim.rlim_max);
    return 0;
}
