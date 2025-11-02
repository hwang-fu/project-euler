#include <stdio.h>
#include <stdint.h>

#define ONE_MILLION (1000000ul)

uint64_t Collatz(uint64_t n)
{
    uint64_t count = 0;
    while (n != 1)
    {
        count++;
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = (3 * n + 1);
        }
    }
    return count;
}

void Solve()
{
    uint64_t ans   = 0;
    uint64_t chain = 0;
    for (uint64_t i = 1; i < ONE_MILLION; i++)
    {
        uint64_t collatz = Collatz(i);
        if (collatz > chain)
        {
            chain = collatz;
            ans = i;
        }
    }

    fprintf(stdout,
            "The starting number %lu under one million has the longest chain with length %lu\n",
            ans, chain);
}

int main()
{
    Solve();
    return 0;
}
