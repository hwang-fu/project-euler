// gcc -lm
#include <math.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Sieve of Eratosthenes.

#ifndef N
#define N (10001ul)
#endif // N

uint64_t solve(uint64_t n)
{
    // Safe upper bound for p_n; 200k easily covers n = 10001.
    const uint64_t limit = 200000ul;

    bool * isComposite = calloc(limit + 1, sizeof(bool));
    if (!isComposite)
    {
        abort();
    }

    uint64_t count = 0ul;

    uint64_t ans = 0ul;

    uint64_t root = sqrt((double) limit);

    for (uint64_t p = 2; p <= limit; p++)
    {
        if (!isComposite[p])
        {
            if (++count == n)
            {
                ans = p;
                break;
            }

            if (p <= root)
            {
                for (uint64_t q = p * p; q <= limit; q += p)
                {
                    isComposite[q] = true;
                }
            }
        }
    }

    free(isComposite);
    return ans;
}

int main()
{
    fprintf(stdout, "The 10001st prime number is: %lu\n", solve(N));
    return 0;
}
