#include <stdio.h>
#include <stdint.h>

/// Idea:
/// a + b + c = 1000
/// a^2 + b^2 = c^2
/// a < b < c
///
/// Any Pythagorean triplet can be written as:
///     a = k (m^2 - n^2)
///     b = k (2mn)
///     c = k (m^2 + n^2)
/// with m >= n >= 1, gcd(m, n) = 1 and k >= 1
/// ...
/// a + b + c = k (2m^2 + 2mn) = 2 k m (m + n) = 1000
/// k m (m + n) = 500

uint64_t gcd(int a, int b)
{
    while (b)
    {
        uint64_t t = a % b;
        a = b;
        b = t;
    }
    return a < 0 ? -a : a;
}

void solve()
{
    const uint64_t S = 1000;

    for (uint64_t m = 2; 2 * m * (m + 1) <= S; m++)
    {
        for (uint64_t n = 1; n < m; n++)
        {
            // skip if m and n have same parity (both odd or both even).
            if (((m - n) & 0b1) == 0)
            {
                continue;
            }

            // skip if m and n share a common factor.
            if (gcd(m, n) != 1)
            {
                continue;
            }

            // now checking `k`, `k` must be an integer.
            uint64_t base = 2 * m * (m + n);
            if (S % base != 0)
            {
                continue;
            }
            uint64_t k = S / base;

            uint64_t a = k * (m * m - n * n);
            uint64_t b = k * (2 * m * n);
            uint64_t c = k * (m * m + n * n);

            uint64_t abc = a * b * c;
            fprintf(stdout, "abc=%lu\n", abc);
            return;
        }
    }

    fprintf(stdout, "triplet not found.\n");
}

int main()
{
    solve();
    return 0;
}
