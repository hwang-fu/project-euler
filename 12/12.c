#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/// Idea:
/// n-th triangular number = n (n + 1) / 2
///
/// if n is even: (n+1) * (n/2)
/// if n is odd : (n)   * ((n+1)/2)
///
/// Assume Tau(n) = number of factors.
///
/// Tau(n * (n + 1) / 2) =
///     Tau(n+1) * Tau(n/2)         if n is even
///     Tau(n)   * Tau((n+1)/2)     if n is odd

// Smallest-Prime-Factor (SPF) Sieve:
// We assume the SPF limit, 5000000 is pretty enough.
//
// However,
// if you don't wanna assume a fixed limit value, you can dynamically grow it,
// it just costs more code.
#define SPF_LIMIT (5000000ul)

#define K (500)

static uint64_t * SPF = NULL;


uint64_t Tau(uint64_t n)
{
    if (n == 1)
    {
        return 1;
    }

    uint64_t tau = 1;
    while (n > 1)
    {
        uint64_t p = SPF[n];
        uint64_t e = 0;
        while (n % p == 0)
        {
            n /= p;
            e++;
        }
        tau *= (e + 1);
    }
    return tau;
}

void Solve()
{
    for (uint64_t n = 1; n < SPF_LIMIT; n++)
    {
        uint64_t tauA = 0;
        uint64_t tauB = 0;

        if ((n & 1) == 0)
        {
            // n is even.
            tauA = Tau(n / 2);
            tauB = Tau(n + 1);
        }
        else
        {
            // n is odd.
            tauA = Tau(n);
            tauB = Tau((n + 1) / 2);
        }

        if (tauA * tauB > K)
        {
            uint64_t nthTriangularNumber = n * (n + 1) / 2;
            fprintf(stdout, "%lu has %lu factors.\n", nthTriangularNumber, tauA * tauB);
            return;
        }
    }
    fprintf(stdout, "Couldn't find it.\n");
}

int main()
{
    SPF = calloc(SPF_LIMIT + 1, sizeof(uint64_t));
    if (!SPF)
    {
        fprintf(stderr, "Failed to initialize SPF!\n");
        exit(EXIT_FAILURE);
    }
    for (uint64_t i = 2; i <= SPF_LIMIT; i++)
    {
        if (SPF[i] != 0)
        {
            continue;
        }

        SPF[i] = i;
        for (uint64_t j = i * i; j <= SPF_LIMIT; j += i)
        {
            if (SPF[j] == 0)
            {
                SPF[j] = i;
            }
        }
    }

    Solve();

    free(SPF);
    return 0;
}
