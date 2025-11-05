// Key observations:
// At n = 0 -> f(0) = b -> So b MUST be prime.
// At n = 1 -> f(1) = 1 + a + b should also be prime.
//  And since b is prime, therefore odd, and all primes are odd numbers,
//  So 1 + a must be even -> a must be also an odd number.
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define A (1000)
#define B (1000)

#define N (1000000)

int8_t Cache[N] = { 0 };

bool IsPrime(uint64_t p)
{
    if (p < 2) return false;

    if ((p & 0b1) == 0)
    {
        if (p < N) Cache[p] = -1;
        return false;
    }

    if (p < N && Cache[p] != 0)
    {
        return Cache[p] == 1;
    }

    for (uint64_t i = 3; i * i <= p; i += 2)
    {
        if (p % i == 0)
        {
            if (p < N) Cache[p] = -1;
            return false;
        }
    }

    if (p < N) Cache[p] = 1;
    return true;
}

int64_t mul(int16_t a, int16_t b)
{
    return (int64_t) a * (int64_t) b;
}

void Solve()
{
    int16_t bestN = 0;
    int64_t ab = 0;

    for (int16_t b = 3; b <= B; b++)
    {
        if (!IsPrime(b))
        {
            continue;
        }

        for (int16_t a = -999; a < A; a += 2)
        {
            int32_t n = 0;
            for (;;++n)
            {
                int64_t f_n = mul(n, n) + mul(a, n) + (int64_t) b;
                if (f_n < 2 || !IsPrime((uint64_t) f_n))
                {
                    break;
                }
            }
            if (n > bestN)
            {
                bestN = n;
                ab = mul(a, b);
            }
        }
    }

    printf("%ld\n", ab);
}

int main()
{
    Cache[0] = -1;
    Cache[1] = -1;
    Cache[2] = 1;
    for (uint16_t i = 3; i <= B; i++)
    {
        IsPrime(i);
    }
    Solve();
    return 0;
}
