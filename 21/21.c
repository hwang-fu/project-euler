#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


#define K (10000)

#define N (10000000)
uint64_t D_n[N] = { 0 };

uint64_t d(uint64_t n)
{
    if (n < N && D_n[n] != 0)
    {
        return D_n[n];
    }

    uint64_t sum = 1;
    for (uint64_t i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    if (n < N)
    {
        D_n[n] = sum;
    }

    return sum;
}

bool IsAmicable(uint64_t n)
{
    return d(d(n)) == n && d(n) != n;
}

void Solve()
{
    uint64_t sum = 0;

    for (uint64_t i = 2; i < K; i++)
    {
        if (IsAmicable(i))
        {
            sum += i;
        }
    }

    printf("%lu\n", sum);
}

int main()
{
    Solve();
    return 0;
}
