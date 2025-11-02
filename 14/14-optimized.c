#include <stdio.h>
#include <stdint.h>

// Idea(s) for optimization:
//
// 1.   if `n` is odd, n = 3n + 1 is even, so you can do two steps at once, which is:
//      n = (3n + 1) / 2; steps += 2;
//
// 2.   Memoization (to cache the Collatz length you've already computed).

#define ONE_MILLION (1000000ul)

#define CACHE_CAPACITY (1ul << 22)

static uint64_t Cache[CACHE_CAPACITY] = { 0 };

uint64_t Collatz(uint64_t n)
{
    uint64_t steps = 0;
    while (n != 1)
    {
        if (n < CACHE_CAPACITY && Cache[n] != 0)
        {
            steps += Cache[n];
            break;
        }

        if (n % 2 == 0)
        {
            n = n / 2;
            steps += 1;
        }
        else
        {
            n = (3 * n + 1) / 2;
            steps += 2;
        }
    }
    return steps;
}

void Solve()
{
    uint64_t ans   = 0;
    uint64_t steps = 0;

    Cache[1] = 0;
    for (uint64_t i = 1; i < ONE_MILLION; i++)
    {
        uint64_t collatz = Collatz(i);

        Cache[i] = collatz;
        if (collatz > steps)
        {
            steps = collatz;
            ans = i;
        }
    }

    fprintf(stdout,
            "The starting number %lu under one million has the longest steps with length %lu\n",
            ans, steps);
}

int main()
{
    Solve();
    return 0;
}

