//This solves n^p mod m using brute force.
#include <stdio.h>


int find_remainder_recursive(int n, int p, int m, int verbose)
{
    int r = 1;
    for(int i = 1; i <= p; i++) {
        r *= n;
        r = r % m;
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
