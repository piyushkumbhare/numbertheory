// This program is made to solve n^p mod m using memoization and dynamic programming.

#pragma once

#include <stdio.h>
#include <stdlib.h>


int* find_remainder_recursivedp(int n, int p, int m, int verbose);

int find_remainder_dp(int n, int p, int m);
