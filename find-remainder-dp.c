// This program is made to solve n^p mod m using memoization and dynamic programming.
#include <stdio.h>

int find_remainder_recursive(int n, int p, int m, int verbose)
{
    int r = 1;
    int M[m]; //Memiozation table for Dynamic Programming. M[i] = j means that "i" was last seen on the "j"th iteration.
    for(int i = 0; i < m; i++) {
        M[i] = 0;
    }
    int last = 1;
    for(int i = 1; i <= p; i++) {
        // if(verbose) printf("i = %d:", i);
        r *= n;
        r = r % m;
        
        if(r == 1 || r == 0 || r == m - 1) { // Finding a 1 is our number 1 priority. It simplifies calculations easily.
            if(r == m - 1) r = -1; //m - 1 = -1 in the modulo world.
            
            if(verbose) printf("%d^%d mod %d = %d !!!\n", n, i, m, r);
            if(verbose) printf("We can exploit %d since the calculation becomes trivial\n", r);
            if(verbose) printf("%d = %d * %d + %d\n", p, p/i, p % i);
            if(verbose) printf("%d^%d ≡ (%d)^%d * %d^%d mod %d\n", n, p, r, p/i, n, p % i, m);
            
            if(r == -1) r = -1 + 2 * !(p/i & 1);
            
            r = r * find_remainder_recursive(n, p % i, m, 0);
            break;
        } else if(M[r] > 0) { //Stored remainder found. This means there's a pattern
            printf("%d^%d mod %d = %d !!!\n", n, i, m, r);
            //M[r] denotes the last "i" at which this remainder was found. 
            //This means the pattern repeats once every i - M[r] iterations
            int repeat = i - M[r];
            
            if(verbose) printf("This pattern repeats once every %d iterations\n", repeat);
            if(verbose) printf("%d = %d * %d + %d\n", p, p/repeat, repeat, p % repeat);
            if(verbose) printf("This means %d^%d ≡ %d^%d mod %d\n", n, p, n, p % repeat, m);
            
            r = find_remainder_recursive(n, p % repeat, m, 0);
            break;
        } else {
            // if(verbose) printf("%d^%d mod %d = %d\n", n, i, m, r);
            
            M[r] = i; //Update the Memoization table.
        }
        
    }
    return r;
}

int find_remainder(int n, int p, int m) {
    printf("Find %d^%d mod %d\n", n, p, m);
    int e = find_remainder_recursive(n, p, m, 1);
    printf("Answer is %d\n", e);
}

int main() {
    // Write C code here
    
    find_remainder(4, 3000, 83);
    return 0;
}
