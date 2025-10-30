#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

#ifndef TWO_MILLION
#define TWO_MILLION (2000000ul)
#endif // TWO_MILLION

/// Idea: Sieve of Eratosthenes

void solve()
{
    uint64_t sum = 0;

    bool * isPrime = malloc(TWO_MILLION * sizeof(bool));
    if (!isPrime)
    {
        fprintf(stderr, "Failed to allocate space for the solution.\n");
        exit(EXIT_FAILURE);
    }

    isPrime[0] = false;
    isPrime[1] = false;
    for (uint64_t i = 2; i < TWO_MILLION; i++)
    {
        isPrime[i] = true;
    }

    // sieve thru p <= sqrt(2000000)
    for (uint64_t p = 2; p * p < TWO_MILLION; p++)
    {
        if (!isPrime[p])
        {
            continue;
        }

        for (uint64_t i = p * p; i < TWO_MILLION; i += p)
        {
            isPrime[i] = false;
        }
    }

    for (uint64_t prime = 2; prime < TWO_MILLION; prime++)
    {
        if (isPrime[prime])
        {

            sum += prime;
        }
    }

    free(isPrime);
    fprintf(stdout, "The sum of all primes below two million is: %lu\n", sum);
}

int main()
{
    solve();
    return 0;
}
