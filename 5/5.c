#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

bool isDivisible(uint64_t dividend)
{
    static uint64_t divisors[10] = {
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    };

    for (uint64_t i = 0; i < 10; i++)
    {
        const uint64_t divisor = divisors[i];
        if (dividend % divisor != 0)
        {
            return false;
        }
    }
    return true;
}

uint64_t solve()
{
    uint64_t n = 1;
    while (!isDivisible(n))
    {
        n++;
    }
    return n;
}


int main()
{
    fprintf(stdout, "The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is %lu\n", solve());
    return 0;
}
