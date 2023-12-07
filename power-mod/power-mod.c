#include <stdio.h>

#include "find-remainder-bf.h"
#include "find-remainder-dp.h"


int main(int argc, char* argv[]) {
    // Write C code here
    if(argc != 4) {
        printf("Incorrect usage: Use ./power-mod n p m\n\t\t in order to find n^p mod m.\n");
        exit(1);
    }
    int n = atoi(argv[1]);
    int p = atoi(argv[2]);
    int m = atoi(argv[3]);
    printf("=======================\nBrute Force Method: \n=======================\n");
    find_remainder_bf(n, p, m);
    printf("\n=======================\nDynamic Method: \n=======================\n");
    find_remainder_dp(n, p, m);


    return 0;
}
