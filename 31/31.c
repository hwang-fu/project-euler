#include <stdio.h>
#include <stdint.h>

#define K (200)


#define N (8)
uint64_t Coins[N] = { 1, 2, 5, 10, 20, 50, 100, 200 };

uint64_t CoinSums(int64_t amount, uint64_t startIdx)
{
    if (amount < 0)
    {
        return 0;
    }
    else if (amount == 0)
    {
        return 1;
    }
    else
    {
        uint64_t count = 0;
        for (uint64_t i = startIdx; i < N; i++)
        {
            count += CoinSums(amount - Coins[i], i);
        }
        return count;
    }
}

void Solve()
{
    printf("%lu\n", CoinSums(K, 0));
}

int main()
{
    Solve();
    return 0;
}
