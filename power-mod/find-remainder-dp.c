// This program is made to solve n^p mod m using memoization and dynamic programming.
#include "find-remainder-dp.h"

int* find_remainder_recursivedp(int n, int p, int m, int verbose)
{
    int r = 1;
    int* retval = calloc(2, sizeof(int));
    int M[m]; //Memiozation table for Dynamic Programming. M[i] = j means that "i" was last seen on the "j"th iteration.
    for(int i = 0; i < m; i++) {
        M[i] = 0;
    }
    for(int i = 1; i <= p; i++) {
        // if(verbose) printf("i = %d:", i);
        r *= n;
        r = r % m;
        retval[1]++;
        if(r == 1 || r == 0 || r == m - 1) { // Finding a 1 is our number 1 priority. It simplifies calculations easily.
            if(r == m - 1) r = -1; //m - 1 = -1 in the modulo world.
            
            if(verbose) printf("%d^%d mod %d = %d !!!\n", n, i, m, r);
            if(verbose) printf("We can exploit %d since the calculation becomes trivial\n", r);
            if(verbose) printf("%d = %d * %d + %d\n", p, p/i, i, p % i);
            if(verbose) printf("%d^%d ≡ (%d)^%d * %d^%d mod %d\n", n, p, r, p/i, n, p % i, m);
            
            if(r == -1) r = -1 + 2 * !(p/i & 1); //Performs a bitwise AND with 1 to get the last bit. This determines if the value is odd or even and lets us find out the sign of -1.

            int* child = find_remainder_recursivedp(n, p % i, m, 0);
            r = r * child[0]; 
            retval[1] += child[1];
            free(child);
            break;
        } else if(M[r] > 0) { //Stored remainder found. This means there's a pattern
            printf("%d^%d mod %d = %d !!!\n", n, i, m, r);
            //M[r] denotes the last "i" at which this remainder was found. 
            //This means the pattern repeats once every i - M[r] iterations
            int repeat = i - M[r];
            
            if(verbose) printf("This pattern repeats once every %d iterations\n", repeat);
            if(verbose) printf("%d = %d * %d + %d\n", p, p/repeat, repeat, p % repeat);
            if(verbose) printf("This means %d^%d ≡ %d^%d * %d^%d mod %d\n", n, p, n, repeat, n, p % repeat, m);
            
            int* child1 = find_remainder_recursivedp(n, repeat, m, 0);
            int* child2 = find_remainder_recursivedp(n, p % repeat, m, 0);
            r = child1[0] * child2[0];
            retval[1] += child1[1] + child2[1];
            free(child1);
            free(child2);
            break;
        } else {
            // if(verbose) printf("%d^%d mod %d = %d\n", n, i, m, r);
            
            M[r] = i; //Update the Memoization table.
        }
        
    }
    if(r < 0) {
        r = m + r;
    }
    retval[0] = r % m;
    return retval;
}

int find_remainder_dp(int n, int p, int m) {
    printf("Find %d^%d mod %d\n", n, p, m);
    int* e = find_remainder_recursivedp(n, p, m, 1);
    printf("Answer is %d, took %d iterations\n", e[0], e[1]);
    int ans = e[1];
    free(e);
    return ans;
}

// int main(int argc, char* argv[]) {
//     // Write C code here
//     if(argc != 4) {
//         printf("Incorrect usage: ./find-remainder-dp n p m\nto find n^p mod m.\n");
//         exit(1);
//     }
//     int n = atoi(argv[1]);
//     int p = atoi(argv[2]);
//     int m = atoi(argv[3]);
//     find_remainder(n, p, m);


//     return 0;
// }
