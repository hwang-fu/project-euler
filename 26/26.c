#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define K (1000)

uint64_t RecipocalCycles(uint64_t d)
{
    int64_t * memo = malloc(d * sizeof(int64_t));
    for (uint64_t i = 0; i < d; i++)
    {
        memo[i] = -1;
    }

    uint64_t rem   = 1 % d;
    uint64_t steps = 0;

    while (rem)
    {
        if (memo[rem] != -1)
        {
            return steps - memo[rem];
        }
        memo[rem] = steps;
        steps++;
        rem = (rem * 10) % d;
    }

    // returns zero indicating non-repetitive.
    return 0;
}

void Solve()
{
    uint64_t d   = 0;
    uint64_t len = 0;
    for (uint64_t i = 2; i < K; i++)
    {
        uint64_t n = RecipocalCycles(i);
        if (n > len)
        {
            len = n;
            d   = i;
        }
    }

    printf("1/%lu contains the longest recurring cyle for d < 1000, the cycle has length %lu\n", d, len);
}

int main()
{
    Solve();
    return 0;
}
