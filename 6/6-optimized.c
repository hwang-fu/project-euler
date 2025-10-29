#include <stdio.h>
#include <stdint.h>

#ifndef N
#define N (100ul)
#endif // N

uint64_t solve(uint64_t n)
{
    return n * (n + 1) * (n - 1) * (3 * n + 2) / 12;
}

int main()
{
    fprintf(stdout, "The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is %lu\n", solve(N));
    return 0;
}
