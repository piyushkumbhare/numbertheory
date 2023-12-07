#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quadratic_residue(int n) {
    
    int* nums = calloc(n, sizeof(int));
    int qr;
    for(int i = 1; i < n; i++) {
        qr = (int)pow(i, 2) % n;
        nums[qr] = 1;
    }

    for(int i = 1; i < n; i++) {
        if(nums[i]) printf("(");
        printf("%d", i);
        if(nums[i]) printf(")");
        printf("\t");
    }
    printf("\n");
    
    free(nums);
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Incorrect usage: To find quadratic residues of N, run ./qr N\n");
        exit(1);
    }
    int n = atoi(argv[1]);
    quadratic_residue(n);
    return 0;
}