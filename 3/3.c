#include <stdint.h>
#include <stdio.h>

#ifndef N
#define N (600851475143ul)
#endif // N

uint64_t solve(uint64_t n)
{
    uint64_t largestPrimeFactor = 0;

    // 1. remove factor 2 ( all the even factors will be eliminated).
    while (n % 2 == 0)
    {
        largestPrimeFactor = 2;
        n /= 2;
    }

    // 2. test odd factors (not necessarily prime) at 3, 5, 7, ...
    for (uint64_t i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            largestPrimeFactor = i;
            n /= i;
        }
    }

    // 3. if n > 1 then n itself is the largest prime factor of @arg {N}.
    if (n > 1)
    {
        largestPrimeFactor = n;
    }

    return largestPrimeFactor;
}

int main()
{
    fprintf(stdout, "The largest prime factor of the number %lu is %lu\n", N, solve(N));
    return 0;
}
