#include <stdint.h>
#include <stdio.h>

#ifndef N
#define N (1000ul)
#endif // N

uint64_t solve(uint64_t n)
{
    uint64_t sum = 0;
    for (uint64_t i = 3; i < n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    fprintf(
            stdout,
            "The sum of all the multiples of 3 or 5 below %lu is: %lu\n",
            N,
            solve( N ));
    return 0;
}
