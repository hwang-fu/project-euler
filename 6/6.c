#include <stdint.h>
#include <stdio.h>

#ifndef N
#define N (100ul)
#endif // N

uint64_t solve(uint64_t n)
{
    uint64_t sumOfSquare = 0ul;
    uint64_t squareOfSum = 0ul;
    for (uint64_t i = 1ul; i <= n; i++)
    {
        sumOfSquare += i * i;
        squareOfSum += i;
    }
    squareOfSum = squareOfSum * squareOfSum;

    return squareOfSum - sumOfSquare;
}

int main()
{
    fprintf(stdout, "The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is %lu\n", solve(N));
    return 0;
}
