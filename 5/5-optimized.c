#include <stdio.h>
#include <stdint.h>

uint64_t gcd(uint64_t a, uint64_t b)
{
    while (b)
    {
        uint64_t temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

uint64_t lcm(uint64_t a, uint64_t b)
{
    return a / gcd(a, b) * b;
}

uint64_t solve()
{
    uint64_t n = 1;
    for (uint64_t x = 2; x <= 20; x++)
    {
        n = lcm(n, x);
    }
    return n;
}

int main()
{
    fprintf(stdout, "The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is %lu\n", solve());
    return 0;
}
