//This solves n^p mod m using brute force.
#include "find-remainder-bf.h"

int find_remainder_recursivebf(int n, int p, int m, int verbose)
{
    int r = 1;
    for(int i = 1; i <= p; i++) {
        r *= n;
        r = r % m;
    }
    return r;
}

int find_remainder_bf(int n, int p, int m) {
    printf("Find %d^%d mod %d\n", n, p, m);
    int e = find_remainder_recursivebf(n, p, m, 1);
    printf("Answer is %d, took %d iterations\n", e, p);
    return e;
}

// int main(int argc, char* argv[]) {
//     // Write C code here
//     if(argc != 4) {
//         printf("Incorrect usage: ./find-remainder-bf n p m\nto find n^p mod m.\n");
//         exit(1);
//     }
//     int n = atoi(argv[1]);
//     int p = atoi(argv[2]);
//     int m = atoi(argv[3]);
//     find_remainder(n, p, m);


//     return 0;
// }
